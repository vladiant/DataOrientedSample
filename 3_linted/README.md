# Version 3

## Changes from previous version 

* Used `cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
* Applied `run-clang-tidy -checks='cppcoreguidelines-*,performance-*,readibility-*,modernize-*,misc-*,clang-analyzer-*' ` 
* Applied `cppcheck  --std=c++17 *.*`

## Performance 

| Case | Time, ms |
|----|---|
| Non-cache friendly | 3601 |
| Cache friendly | 2519 |

## Executable size

24352 bytes