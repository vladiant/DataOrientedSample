# Version 4

## Changes from previous version 

* Used `nullptr`
* Removed default constructors and destructors
* Added virtual destructor for base class
* Replaced `emplace_back` with `push_back` for raw pointers

## Performance 

| Case | Time, ms |
|----|---|
| Non-cache friendly | 3605 |
| Cache friendly | 2521 |

## Executable size

24648 bytes