#pragma once

// A singly linked-list node holding a value of any type T.
template <typename T>
class Node {
    private:
        Node<T>* next;
        T value;

    public:
        Node(T value) : next(nullptr), value(value) {}

        Node<T>* getNext(){
            return next;
        }
        T getValue(){
            return value;
        }

        void setNext(Node<T>* next){
            this->next = next;
        }

        void setValue(T value){
            this->value = value;
        }
};
