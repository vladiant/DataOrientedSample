# Cache Friendly Data

## Command

### Setup

```bash
sudo apt install linux-tools-common
sudo apt install linux-tools-5.15.0-121-generic
```

### Measure
Apply on Release build

```bash
sudo perf stat -e cache-references,cache-misses,L1-dcache-prefetches,instructions,cpu-cycles,branches,branch-misses,duration_time 
```

## vector_of_structs VS struct_of_vectors

### struct_of_vectors
* fewer memory accesses
* fewer cache misses
* slightly fewer instructions
* siginificantly faster
* least readable code

## templated
* similar performance to `struct_of_vectors`

## Stable Row Id
A stable row ID to lookup objects

### row_id

### filter_templated

### filter_row_id_gen

## Iterator interface to work with ranges

### filter_iterators

### iterators_row

### filter_iterators_row

## Selecting columns
Convenient way to look at only some columns

### filter_row_select_gen

### filter_function_select_gen

## References
* [C++ Cache Friendly Data + Functional + Ranges = ❤️ - Björn Fahller - C++ on Sea 2024](https://www.youtube.com/watch?v=XJzs4kC9d-Y)
* [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc)
* [Data Storage in Entity Component Systems - Mathieu Ropert - Meeting C++ 2023](https://www.youtube.com/watch?v=b9hNKFj5R3Y)
* <https://github.com/rollbear/cache_functional_ranges>

