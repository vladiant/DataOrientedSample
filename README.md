# DataOrientedSample
Sample for Data Oriented design in C++

## Code base 

* [https://github.com/jeuxdemains/CPUCacheFriendlyCode](https://github.com/jeuxdemains/CPUCacheFriendlyCode)

## Execution speed 

### Increased
* Removed inheritance, Added usage of void pointer cotnainers, Objects casted to and from void pointer
* Make components templated

### Decreased
* Separated implementations from declarations, Used vector instead of raw memory buffer
* Replaces raw pointers with smart pointers except ones using `this`
* Uses `weak_from_this`, Replace `shared_ptr` with `unique_ptr`

### Not changed
* Forward declarations, Formatting, `clang-tidy` and `cppcheck` findings applied
* Used `nullptr`, Removed default constructors and destructors, Added virtual destructor for base class, Replaced `emplace_back` with `push_back` for raw pointers
* Separated implementations from declarations
* Used vector instead of raw memory buffer

## Executable size

### Increased
* Used `nullptr`, Removed default constructors and destructors, Added virtual destructor for base class, Replaced `emplace_back` with `push_back` for raw pointers
* Removed inheritance, Added usage of void pointer cotnainers, Objects casted to and from void pointer
* Separated implementations from declarations, Used vector instead of raw memory buffer
* Replaces raw pointers with smart pointers except ones using `this`
* Uses `weak_from_this`, Replace `shared_ptr` with `unique_ptr`

### Not changed
* Forward declarations, Formatting, `clang-tidy` and `cppcheck` findings applied
* Make components templated

## References
* [What is Data Oriented Programming?](https://blog.klipse.tech/databook/2020/09/25/data-book-chap0.html)

* [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc)

* [CppCon 2018: Stoyan Nikolov “OOP Is Dead, Long Live Data-oriented Design”](https://www.youtube.com/watch?v=yy8jQgmhbAU)

* [C++ Crash Course: Data Oriented Design](https://www.youtube.com/watch?v=XpYORLssFW8)

* [Data oriented game design](https://www.youtube.com/watch?v=GY9RytdA1mA)

* [The price of dynamic memory: Allocation](https://johnysswlab.com/the-price-of-dynamic-memory-allocation/)

* <https://github.com/rollbear/cache-friendly-samples>
