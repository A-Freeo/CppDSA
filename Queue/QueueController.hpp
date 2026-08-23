#pragma once
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>

// Classic queue algorithms as free function templates in a namespace.
// Each takes the queue by value (its own deep copy), so callers aren't mutated.
namespace QueueController {

    // --- Printing ---

    // Print the queue front-to-back by walking the nodes (no dequeuing).
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

    // --- Algorithms ---

    // Reverse a queue: dequeue everything onto a stack (LIFO), then pop it back in.
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

    // Reverse only the first k elements; keep the rest in order.
    // Pop the first k off a stack into a new queue (reversed), then append the rest.
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

    // Interleave the front half with the back half: a1 b1 a2 b2 ...
    template<typename T>
    Queue<T> interleave(Queue<T> queue){
        // Count the length first (read-only) — can't walk a pointer while
        // dequeue() is deleting those same nodes.
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
