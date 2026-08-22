#pragma once
#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
#include <vector>

// Classic stack algorithms. Free function templates in a namespace
// (C++'s take on Java's class-of-static-methods controller).
namespace StackController {

    // --- Printing ---

    // Print the stack top-to-bottom by walking the nodes (no popping).
    template<typename T>
    void dump(Stack<T> stack){
        Node<T>* current = stack.topNode();   // nullptr if empty
        int i = 0;

        while(current != nullptr){
            std::cout << "Item " << i << ": " << current->getValue() << "\n";
            i++;
            current = current->getNext();
        }
    }


    // --- Algorithms ---

    // Are the brackets balanced? Push openers, match each closer against the top.
    inline bool validParenthesis(std::string s){
        Stack<char> stack;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                stack.push(c);
            } else {
                if(stack.empty()) return false;
                char top = stack.pop();
                if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) return false;
            }
        }
        return stack.empty();
    }

    // Reverse a stack by popping onto a second stack (takes its own deep copy by value).
    template<typename T>
    Stack<T> reverse(Stack<T> stack){
        Stack<T> newStack;
        while(!(stack.empty())){
            newStack.push(stack.pop());
        }
        return newStack;
    }

    // For each element, the next element to its right that's greater (-1 if none).
    // Monotonic stack: it holds indices whose answer isn't found yet.
    inline std::vector<int> NextGreaterElement(std::vector<int> nums){

        int n = nums.size();
        Stack<int> stack;
        std::vector<int> result(n, -1);

        for(int i = 0; i < n; i ++){
            while(!(stack.empty()) && nums[stack.top()] < nums[i]){
                result[stack.pop()] = nums[i];
            }
            stack.push(i);
        }
        
        return result;
    }

};
