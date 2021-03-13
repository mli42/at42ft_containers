# at42ft_containers
Reimplement some containers of the STL (vector, list, map, stack, queue && their iterators, const_iterators, reverse_iterators) [C++98]

What is a [container](https://www.cplusplus.com/reference/stl/) ?

```
A container is a holder object that stores a collection of other objects (its elements).
They are implemented as class templates, which allows a great flexibility in the types supported as elements.

The container manages the storage space for its elements and provides member functions to access them,
either directly or through iterators (reference objects with similar properties to pointers).
```

[Abstraction in C++](https://www.geeksforgeeks.org/abstraction-in-c/):

```
Data abstraction is one of the most essential and important feature of object oriented programming in C++.
Abstraction means displaying only essential information and hiding the details.
Data abstraction refers to providing only essential information about the data to the outside world,
hiding the background details or implementation.
```

So, what are these containers abstracting?

```
- vector: Dynamic contiguous array
- list: Circular double linked list
- map: Binary Search Tree of key-value pairs, sorted by unique keys.
- stack: Adapts a container to provide stack (LIFO - Last In First Out)
- queue: Adapts a container to provide queue (FIFO - First In First Out)
```

Btw, I made my own tester 🥳 : https://github.com/mli42/containers_test

## Tips for this project
<p>
  <img src="https://user-images.githubusercontent.com/52219651/111030211-545ac280-8401-11eb-8e5d-8d05e2e4fdad.png" align="right">

  My recommended order: `vector > list > map > stack/queue`
  
  You should make a spreadsheet with a color-code with every method you have to do in every containers, gathering methods:
  - to do (white),
  - implemented (light green),
  - tested (darker green),
  - does not exist (dark grey)
  
  Don't be afraid to spend time on iterators
</p> <br clear="all"/>
