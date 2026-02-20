# Custom Allocators

## Problems
* The Speed Trap - instaneous allocation
* Memory Chaos - eliminate fragmentation
* Caching - perfect layout for cache

## Standard Allocator
* [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator.html)
* The Allocator Contract
* [std::allocator_traits](https://en.cppreference.com/w/cpp/memory/allocator_traits.html)

## Arena (linear/bump allocator)

Fastest and simplest allocator

### Best for
* Temporary frame data

## Pool Allocator

Recycling objects of same size

### Advantages
* Extremely fast
* Eliminates memory fragmentation for object type

### Disadvantages
* Only works for single, fixed size
* Reserves a potentially large block of memory up front

### Best for
* Nodes in a list, tree or graph
* Gamma objects like bullets, enemies or particles
* Any system that frequently creates and destroys many objects of the same size
* Used in Gaming, Embedded

## Stack Allocator

Ultra fast, temporary

### Advantages
* Fastest possible allocation
* Zero fragmentation
* Move single pointer for free

### Disadvantages
* Cannot deallocate individual objects out of order
* Dificult for unpredictable lifetimes

### Best for
* Scratchpad Memory
* Game engines, like allocating memory to handle a single frame
* The best tool for short-lived data
* Used in Trading

## Slab Allocator

## Tracking Allocator


## References
* [Back to Basics: Custom Allocators Explained - From Basics to Advanced - Kevin Carpenter - CppCon](https://www.youtube.com/watch?v=RpD-0oqGEzE)
* <https://github.com/kevinbcarpenter/b2b-custom-allocators>
* [Кастомные аллокаторы для игровых движков: arena, pool и slab на C++](https://habr.com/ru/companies/otus/articles/988086/)
* [CppCon 2017: Bob Steagall “How to Write a Custom Allocator”](https://www.youtube.com/watch?v=kSWfushlvB8)
* [CppCon 2015: Andrei Alexandrescu “std::allocator...”](https://www.youtube.com/watch?v=LIb3L4vKZ7U)