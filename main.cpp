#include "LinkedList.hpp"
#include "LinkedListController.hpp"
#include "Node.hpp"
#include <iostream>

int main(){

    // --- middleNode ---
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    Node<int>* temp = LinkedListController::middleNode(list.getHead());
    int value = temp->getValue();
    std::cout << value << std::endl;   // middle of 1 2 3 4

    list.clear();

    // --- bubbleSort ---

    list.add(5);
    list.add(4);
    list.add(7);
    list.add(10);
    list.add(0);
    std::cout << "--------- Sorting --------- "<< std::endl;
    std::cout << "----- Before (bubble) ----- "<< std::endl;
    LinkedListController::print(list.getHead());
    LinkedListController::bubbleSort(list.getHead());
    std::cout << "----- After (bubble) ----- "<< std::endl;
    LinkedListController::print(list.getHead());


    return 0;
}