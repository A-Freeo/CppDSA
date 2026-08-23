#include "Stack.hpp"
#include "StackController.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::cout << "========== Stack demo ==========\n";

    // --- push + dump ---
    Stack<int> s;
    for(int x : {5, 3, 8, 1}) s.push(x);
    std::cout << "\n=== push 5 3 8 1, dump (top -> bottom) ===\n";
    StackController::dump(s);

    // --- top / empty ---
    std::cout << "\n=== top / empty ===\n";
    std::cout << "top()   = " << s.top() << "\n";
    std::cout << "empty() = " << (s.empty() ? "true" : "false") << "\n";

    // --- pop ---
    std::cout << "\n=== pop ===\n";
    std::cout << "pop() = " << s.pop() << "\n";
    std::cout << "after pop:\n";
    StackController::dump(s);

    // --- reverse (deep copy: original left untouched) ---
    std::cout << "\n=== reverse (returns a new stack; original untouched) ===\n";
    Stack<int> r = StackController::reverse(s);
    std::cout << "reversed:\n";
    StackController::dump(r);
    std::cout << "original still intact:\n";
    StackController::dump(s);

    // --- clear ---
    std::cout << "\n=== clear ===\n";
    s.clear();
    std::cout << "after clear, empty() = " << (s.empty() ? "true" : "false") << "\n";

    // --- validParenthesis ---
    std::cout << "\n=== validParenthesis ===\n";
    for(std::string test : {"({[]})", "(]", "((("}){
        std::cout << "\"" << test << "\" -> "
                  << (StackController::validParenthesis(test) ? "valid" : "invalid") << "\n";
    }

    // --- NextGreaterElement ---
    std::cout << "\n=== NextGreaterElement ===\n";
    std::vector<int> nums = {2, 1, 3, 0, 4};
    std::cout << "nums   : ";
    for(int n : nums) std::cout << n << " ";
    std::cout << "\nresult : ";
    for(int v : StackController::NextGreaterElement(nums)) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
