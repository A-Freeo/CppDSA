#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Node.hpp"

// Singly linked list of Node<T>. Holds only the head; the controller
// (LinkedListController) provides the algorithms.
template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList() : head(nullptr) {}

        Node<T>* getHead(){
            return head;
        }

        // --- Core operations ---

        // Append a value to the tail (walks to the end first).
        void add(T value){
            if(head == nullptr){
                head = new Node<T>(value);
                return;
            }
            Node<T>* temp = head;
            while(temp->getNext() != nullptr){
                temp = temp->getNext();
            }

            temp->setNext(new Node<T>(value));

        }

        // Remove every node equal to value (uses a dummy head to simplify the edge case).
        // BUG: after a delete, prev/current still advance, so the node right after a
        //      removed one is skipped (e.g. consecutive duplicates aren't all removed).
        Node<T>* remove(T value){
            if(head == nullptr) return nullptr;

            Node<T>* dummy = new Node<T>();
            dummy->setNext(head);

            Node<T>* prev = dummy;
            Node<T>* current = head;
            while(current != nullptr){
                if(current->getValue() == value){
                    prev->setNext(current->getNext());
                    delete current;
                    current = prev->getNext();
                }
                prev = current;
                current = current->getNext();
            }
            head = dummy->getNext();
            delete dummy;
            return head;
        }

        // Insert value at 1-indexed position n (n <= 1 makes it the new head).
        // If n is past the end, the value is appended at the tail.
        void insert(T value, int n){
            Node<T>* newNode = new Node<T>(value);
            if(head == nullptr || n <= 1){
                newNode->setNext(head);
                head = newNode;
                return;
            }
            Node<T>* temp = head;
            for(int i = 0; i < n - 2 && temp->getNext() != nullptr; i++){
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }

        // Free every node and reset to empty.
        void clear(){
            Node<T>* next = nullptr;
            while(head != nullptr){
                next = head->getNext();
                delete head;
                head = next;
            }
        }
    };