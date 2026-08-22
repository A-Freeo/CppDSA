#include "Queue.hpp"
#include "QueueController.hpp"
#include <iostream>

int main(){
    std::cout << "========== Queue demo ==========\n";

    // --- enqueue + dump ---
    Queue<int> q;
    for(int x : {1, 2, 3, 4, 5}) q.enqueue(x);
    std::cout << "\n=== enqueue 1 2 3 4 5, dump (front -> back) ===\n";
    QueueController::dump(q);

    // --- front / empty ---
    std::cout << "\n=== front / empty ===\n";
    std::cout << "front() = " << q.front() << "\n";
    std::cout << "empty() = " << (q.empty() ? "true" : "false") << "\n";

    // --- dequeue ---
    std::cout << "\n=== dequeue ===\n";
    std::cout << "dequeue() = " << q.dequeue() << "\n";
    std::cout << "after dequeue:\n";
    QueueController::dump(q);

    // --- reverse (returns a new queue; original untouched) ---
    std::cout << "\n=== reverse ===\n";
    QueueController::dump(QueueController::reverse(q));

    // --- reverseFirstK ---
    std::cout << "\n=== reverseFirstK (k = 2) ===\n";
    QueueController::dump(QueueController::reverseFirstK(q, 2));

    // --- interleave ---
    std::cout << "\n=== interleave ===\n";
    QueueController::dump(QueueController::interleave(q));

    // --- clear ---
    std::cout << "\n=== clear ===\n";
    q.clear();
    std::cout << "after clear, empty() = " << (q.empty() ? "true" : "false") << "\n";

    return 0;
}
