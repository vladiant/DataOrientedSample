# Version 7

## Changes from previous version 

* Uses `weak_from_this`
* Replace `shared_ptr` with `unique_ptr`

## Performance 

| Case | Time, ms |
|----|---|
| Non-cache friendly | 4430 |
| Cache friendly | 3116 |

## Executable size

47040 bytes
