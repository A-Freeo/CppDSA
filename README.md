# CppDSA

Data-structures and algorithms practice in C++ — the C++ counterpart to
[JavaDSA](https://github.com/A-Freeo/JavaDSA). Each structure is hand-implemented
(templated) to practice pointer manipulation, memory management, templates, and common
interview patterns.

Each structure lives in its own folder and compiles on its own.

## What's here

| Folder | Structure |
|---|---|
| [`LinkedList/`](LinkedList) | Templated singly linked list + a controller of classic list algorithms |
| [`Stack/`](Stack) | Templated stack (with the Rule of Three) + controller; see `Stack/NOTES.md` |
| [`Queue/`](Queue) | Templated queue (head + tail pointers, O(1) enqueue) + controller |
| [`Vector/`](Vector) | Dynamic array (`std::vector` from scratch) — raw array that doubles on growth |

Each folder holds the templated headers (`Node.hpp`, the container, its controller) plus a
`main.cpp` demo driver.

## Build & run

```
cd Stack        # or LinkedList / Queue
g++ main.cpp -o main
./main
```

## Roadmap

- [x] Linked list — reverse, palindrome, cycle detection, Nth-from-end, sorts, merge
- [x] Stack — validParenthesis, reverse, next-greater-element, Rule of Three
- [x] Queue — reverse, reverseFirstK, interleave
- [x] Dynamic array (Vector) — raw array + resize-on-grow, Rule of Three
- [ ] Hash map from scratch (buckets + collision handling)
- [ ] Binary search tree — insert, search, delete, traversals
- [ ] Min-heap / priority queue
