#pragma once
#include "Node.hpp"
#include <stdexcept>

// FIFO queue built on Node<T>.
//   head = FRONT (where we dequeue),  tail = BACK (where we enqueue).
// The tail pointer makes enqueue O(1) instead of walking the whole list.
template <typename T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        Queue() : head(nullptr), tail(nullptr) {}

        ~Queue(){
           clear();
        }
       
        Queue(const Queue<T>& other){
            head = nullptr;
            tail = nullptr;

            Node<T>* srcHead = other.head;

            while(srcHead != nullptr){
                Node<T>* newNode = new Node<T>(srcHead->getValue());
                if(head == nullptr){ head = newNode; tail = newNode; }
                else{ tail->setNext(newNode); tail = newNode; }
                srcHead = srcHead->getNext();
            }
        }

        Queue<T>& operator=(const Queue<T>& other){
            if(this == &other) return *this;
            clear();

            head = nullptr;
            tail = nullptr;

            Node<T>* srcHead = other.head;

            while(srcHead != nullptr){
                Node<T>* newNode = new Node<T>(srcHead->getValue());
                if(head == nullptr){ head = newNode; tail = newNode; }
                else{ tail->setNext(newNode); tail = newNode; }
                srcHead = srcHead->getNext();
            }
            return *this;
        }

        // --- Core operations ---
        void enqueue(T value){
            Node<T>* newNode = new Node<T>(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->setNext(newNode);
            tail = newNode;
        }


        T dequeue(){
            if(head == nullptr) throw std::runtime_error("dequeue from empty queue");
            
            Node<T>* node = head;
            T value = node->getValue();

            head = head->getNext();

            if(head == nullptr){
                tail = nullptr;
            }

            delete node;
            return value;
        }

        T front(){
            if(head == nullptr) throw std::runtime_error("front of empty queue");
            return head->getValue();
        }

        bool empty(){
            if(!(head == nullptr)) return false;
            return true;
        }

        void clear(){
            Node<T>* temp = head;
            tail = nullptr;
            head = nullptr;
            while(temp != nullptr){
                Node<T>* next = temp->getNext();
                delete temp;
                temp = next;
            }
        }

        Node<T>* frontNode(){
            return head;
        }
};
