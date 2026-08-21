#pragma once
#include "Node.hpp"
#include <stdexcept>

template <typename T>
class Stack{
    private:
        Node<T>* top;
    public:
        Stack() : top(nullptr) {}

        void push(T value){

            Node<T>* temp = new Node<T>(value);
            if(top == nullptr){
                top = temp;
                return;
            }
            temp->setNext(top);
            top = temp;
        }
        T peek(){
            if(top == nullptr) throw std::runtime_error("peek from empty stack");
            return top->getValue();
        }
        // Top node, for controllers that need to walk the stack (e.g. dump).
        Node<T>* getTop(){
            return top;
        }
        T pop(){
            if(top == nullptr) throw std::runtime_error("pop from empty stack");
            T value = top->getValue();
            Node<T>* toDelete = top;
            top = top->getNext();
            delete toDelete;
            return value;
        }

        bool isEmpty(){
            if(top == nullptr){
                return true;
            }else{
                return false;
            }
        }
        void clear(){
            Node<T>* next;
            while(top != nullptr){
                next = top->getNext();
                delete top;
                top = next;
            }
            top = nullptr;
        }

};
