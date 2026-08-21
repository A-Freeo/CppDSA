#pragma once
#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace StackController {

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

    template<typename T>
    Stack<T> reverse(Stack<T> stack){
        Stack<T> newStack;
        while(!(stack.empty())){
            newStack.push(stack.pop());
        }
        return newStack;
    }

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
