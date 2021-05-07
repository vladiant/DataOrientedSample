# Version 5

## Changes from previous version 

* Replaces raw pointers with smart pointers except ones using `this`

## Performance 

| Case | Time, ms |
|----|---|
| Non-cache friendly | 5624 |
| Cache friendly | 2946 |

## Executable size

43120 bytes
