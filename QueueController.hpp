#pragma once
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>

namespace QueueController {

    template<typename T>
    void dump(Queue<T> queue){
        Node<T>* current = queue.frontNode();
        int i = 0;
        while(current != nullptr){
            std::cout << "Item " << i << ": " << current->getValue() << "\n";
            i++;
            current = current->getNext();
        }
    }

    
    template<typename T>
    Queue<T> reverse(Queue<T> queue){
        Stack<T> tempStack;
        while(!queue.empty()){
            tempStack.push(queue.dequeue());
        }
        while(!tempStack.empty()){
            queue.enqueue(tempStack.pop());
        }
        return queue;
    }

    template<typename T>
    Queue<T> reverseFirstK(Queue<T> queue, int k){
        Stack<T> tempStack;
        Queue<T> result;
        for(int i = 0; i < k; i++){
            if(queue.empty()) break;
            tempStack.push(queue.dequeue());
        }
        for(int i = 0; i < k; i++){
            if(tempStack.empty()) break;
            result.enqueue(tempStack.pop());
        }
        while(!(queue.empty())){
            result.enqueue(queue.dequeue());
        }
        return result;
    }

    template<typename T>
    Queue<T> interleave(Queue<T> queue){
        int n = 0;
        for(Node<T>* p = queue.frontNode(); p != nullptr; p = p->getNext()) n++;

        Queue<T> firstHalf;
        for(int i = 0; i < n / 2; i++){
            firstHalf.enqueue(queue.dequeue());
        }

        Queue<T> newQueue;
        while(!firstHalf.empty()){
            newQueue.enqueue(firstHalf.dequeue());
            newQueue.enqueue(queue.dequeue());
        }
        while(!queue.empty()){
            newQueue.enqueue(queue.dequeue());
        }

        return newQueue;
    }
}
