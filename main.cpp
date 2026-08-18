#include "Stack.hpp"
#include "StackController.hpp"
#include "Node.hpp"

int main(){
    Stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    StackController::dump(stack);
    
    return 0;
}