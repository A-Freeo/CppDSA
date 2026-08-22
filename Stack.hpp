#pragma once
#include "Node.hpp"
#include <stdexcept>

template <typename T>
class Stack{
    private:
        Node<T>* topPtr;
    public:
        Stack() : topPtr(nullptr) {}

        // --- Rule of Three ---
        // We own raw nodes, so shallow copies share them and the destructor
        // then double-frees. Fix: free on death, and always deep-copy.

        // Free every node when the stack dies.
        ~Stack(){
            clear();
        }

        // Deep copy into a NEW stack. Tail-append keeps the original's order.
        Stack(const Stack<T>& other){
            topPtr = nullptr;
            Node<T>* src  = other.topPtr;
            Node<T>* tail = nullptr;
            while(src != nullptr){
                Node<T>* n = new Node<T>(src->getValue());
                if(tail == nullptr) topPtr = n;
                else tail->setNext(n);
                tail = n;
                src = src->getNext();
            }
        }

        // Deep copy over an existing stack: self-guard, drop old nodes, copy.
        Stack<T>& operator=(const Stack<T>& other){
            if(this == &other) return *this;
            clear();

            Node<T>* src  = other.topPtr;
            Node<T>* tail = nullptr;
            while(src != nullptr){
                Node<T>* n = new Node<T>(src->getValue());
                if(tail == nullptr) topPtr = n;
                else tail->setNext(n);
                tail = n;
                src = src->getNext();
            }
            return *this;
        }

        void push(T value){
            Node<T>* temp = new Node<T>(value);
            if(topPtr == nullptr){
                topPtr = temp;
                return;
            }
            temp->setNext(topPtr);
            topPtr = temp;
        }
        T top(){
            if(topPtr == nullptr) throw std::runtime_error("top of empty stack");
            return topPtr->getValue();
        }
        
        Node<T>* topNode(){
            return topPtr;
        }
        T pop(){
            if(topPtr == nullptr) throw std::runtime_error("pop from empty stack");
            T value = topPtr->getValue();
            Node<T>* toDelete = topPtr;
            topPtr = topPtr->getNext();
            delete toDelete;
            return value;
        }

        bool empty(){
            return topPtr == nullptr;
        }
        void clear(){
            Node<T>* next;
            while(topPtr != nullptr){
                next = topPtr->getNext();
                delete topPtr;
                topPtr = next;
            }
            topPtr = nullptr;
        }
};
