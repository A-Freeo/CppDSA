# Rule of Three — Notes

Why my Stack has a destructor, a copy constructor, and operator=.

```
//-------------------- The rule --------------------

If a class owns raw `new` memory and needs ONE of these, it needs all three:
  destructor        -> free the nodes when the stack dies
  copy constructor  -> deep-copy when a stack is CREATED from another
  operator=         -> deep-copy when an existing stack is REASSIGNED (a = b)


//-------------------- Shallow vs deep --------------------

shallow (compiler default): copies the topPtr pointer -> two stacks share nodes.
deep (what I wrote):        new a node per value       -> each stack owns its own.

The copy loop makes NEW nodes and tail-appends them (push would reverse order).


//-------------------- Why the destructor forces a deep copy --------------------

1. by-value copy is shallow -> the copy shares the original's nodes (two owners).
2. the copy dies -> its destructor frees those shared nodes.
3. the original now points to freed nodes -> double-free -> crash.

Deep copy fixes it: each stack owns its own nodes, so each destructor
frees only its own.  (Tested: keep destructor, remove copy ctor -> dump() crashes.)


//-------------------- When they run (compiler calls them, not me) --------------------

  }              (scope end)     -> destructor
  by value / Stack b = a         -> copy constructor
  a = b          (both exist)    -> operator=

dump/reverse take Stack BY VALUE (no &) -> that's why they copy.
Pass by reference (Stack<T>&) -> no copy -> none of these run.


//-------------------- Copy ctor vs operator= --------------------

Same deep-copy loop inside. Difference:
  copy ctor: object is being CREATED -> just build it.
  operator=: object EXISTS -> self-guard, clear() old nodes, deep-copy, return *this.


//-------------------- When do I need this? --------------------

Only when I own raw `new` memory (like these nodes).
std::stack / std::vector / smart pointers already handle it -> then I write
nothing (that's the "Rule of Zero").


//-------------------- Later --------------------

  Rule of Five  -> add move constructor + move assignment.
  copy-and-swap -> operator= via the copy ctor + swap (no duplicate loop).
```
