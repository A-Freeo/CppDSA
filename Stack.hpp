#pragma once
#include "Node.hpp"
#include <stdexcept>

template <typename T>
class Stack{
    private:
        Node<T>* topPtr;
    public:
        Stack() : topPtr(nullptr) {}

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
        // Top node, for controllers that need to walk the stack (e.g. dump).
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
