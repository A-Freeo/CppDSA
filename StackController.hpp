#pragma once
#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>

namespace StackController {

    // Print the stack top-to-bottom by walking the nodes (no popping).
    template<typename T>
    void dump(Stack<T> stack){
        if(stack.isEmpty()) return;   // peek() throws on empty, so bail first
        Node<T>* current = stack.peek();
        int i = 0;

        while(current != nullptr){
            std::cout << "Item " << i << ": " << current->getValue() << "\n";
            i++;
            current = current->getNext();
        }
    }
};
