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

## vector_of_structs setup influence

| vector_of_structs setup  | cache-references | cache-misses | instructions | cpu-cycles  | branches    | branch-misses | duration_time, ns |
| ------------------------ | ---------------- | ------------ | ------------ | ----------- | ----------- | ------------- | ----------------- |
| Basic                    | 2286868355       | 21.254 %     | 55257775208  | 17495420238 | 10020196041 | 0.03%         | 4468534359        |
| Array                    | 2317241657       | 20.582 %     | 55226880187  | 17845067340 | 10026661054 | 0.03%         | 4560701464        |
| C Array                  | 2310673988       | 20.568 %     | 55276554235  | 17865587967 | 10025055147 | 0.03%         | 4562179276        |
| constexpr code gen       | 2313624966       | 20.152 %     | 54925777812  | 17690694699 |  9982626444 | 0.01%         | 4504327743        |
| code gen                 | 2425288765       | 20.243 %     | 54932013137  | 19262801054 |  9985158806 | 0.01%         | 4928504320        |

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

