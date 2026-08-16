# CppDSA

Data-structures and algorithms practice in C++ — the C++ counterpart to
[JavaDSA](https://github.com/A-Freeo/JavaDSA). Each structure is hand-implemented to
practice pointer manipulation, memory management, and common interview patterns.

## What's here

- **Linked list** — `Node.cpp` — a `Node` class (raw `Node*` links) and a `LinkedList`
  with a set of classic algorithms (table below).

### LinkedList algorithms

| Method | Problem |
|---|---|
| `add` | Append a value to the tail |
| `insert` | Insert a value at a 1-indexed position |
| `reverse` | Reverse the list (iterative) |
| `reverseRecursive` | Reverse the list (recursive) |
| `middleNode` | Find the middle node (fast/slow pointers) |
| `isPalindrome` | Check if the list reads the same both ways |
| `twoSum` | Find a pair adding to a target (hash map) |
| `cycleDetection` | Detect a cycle (fast/slow pointers) |
| `getNthNodeFromEnd` | Find the Nth node from the end |
| `removeNthNodeFromEnd` | Remove the Nth node from the end |
| `bubbleSort` | Sort the list in place |
| `insertionSort` | Sort the list in place (value-based insertion) |
| `mergeTwoLists` | Merge two lists into one sorted list |

## Build & run

```
g++ Node.cpp -o Node
./Node
```

## Roadmap

- [x] Linked list — traversal, two-sum, palindrome, cycle detection, Nth-from-end, sorts
- [ ] Stack
- [ ] Queue
- [ ] Hash map from scratch (buckets + collision handling)
- [ ] Binary search tree — insert, search, delete, traversals
- [ ] Dynamic array (`std::vector` from scratch) — raw backing array + resize-on-grow
- [ ] Min-heap / priority queue
