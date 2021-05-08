# Version 6

## Changes from previous version 

* Replaces raw pointers with smart pointers except ones using `this`

## Performance 

| Case | Time, ms |
|----|---|
| Non-cache friendly | 4780 |
| Cache friendly | 2612 |

## Executable size

43120 bytes
