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
| Basic                    | 2286868355       | 21.254%      | 55257775208  | 17495420238 | 10020196041 | 0.03%         | 4468534359        |
| Array                    | 2317241657       | 20.582%      | 55226880187  | 17845067340 | 10026661054 | 0.03%         | 4560701464        |
| C Array                  | 2310673988       | 20.568%      | 55276554235  | 17865587967 | 10025055147 | 0.03%         | 4562179276        |
| constexpr code gen       | 2313624966       | 20.152%      | 54925777812  | 17690694699 |  9982626444 | 0.01%         | 4504327743        |
| code gen                 | 2425288765       | 20.243%      | 54932013137  | 19262801054 |  9985158806 | 0.01%         | 4928504320        |

## vector_of_structs VS struct_of_vectors

### struct_of_vectors
* fewer memory accesses
* fewer cache misses
* slightly fewer instructions
* siginificantly faster
* least readable code

## templated
* similar performance to `struct_of_vectors`

| vector usage      | cache-references | cache-misses | instructions | cpu-cycles  | branches    | branch-misses | duration_time, ns |
| ----------------- | ---------------- | ------------ | ------------ | ----------- | ----------- | ------------- | ----------------- |
| vector_of_structs | 2425288765       | 20.243%      | 54932013137  | 19262801054 |  9985158806 | 0.01%         | 4928504320        |
| struct_of_vectors | 671009275        | 1.425%       | 45027939288  | 10290274244 |  9967927669 | 0.01%         | 2775468400        |
| templated         | 703145805        | 8.297%       | 44978495043  | 10433181704 |  9979916163 | 0.01%         | 2674998497        |

## Stable Row Id
A stable row ID to lookup objects

### row_id

### filter_templated

### filter_row_id_gen

| implementation    | cache-references | cache-misses | instructions | cpu-cycles   | branches      | branch-misses | duration_time, ns |
| ----------------- | ---------------- | ------------ | ------------ | ------------ | ------------- | ------------- | ----------------- |
| row_id            | 730259804        | 3.03%        | 45115157422  | 10638601456  |  10020181343  | 1144980       | 2797277504        |
| filter_templated  | 6461247140       | 0.58%        | 400404359239 | 151198426981 |  100070611567 | 1645223       | 39182453364       |
| filter_row_id_gen | 7024634018       | 6.65%        | 400831896052 | 155329132897 |  100150174742 | 2206328       | 41359616969       |

## Iterator interface to work with ranges

### filter_iterators

### iterators_row

### filter_iterators_row

| implementation           | cache-references | cache-misses | instructions | cpu-cycles   | branches      | branch-misses | duration_time, ns |
| ------------------------ | ---------------- | ------------ | ------------ | ------------ | ------------- | ------------- | ----------------- |
| filter_iterators         | 6506112395       | 15.68%       | 250647487743 | 63442406513  |  100124569171 | 1337880       | 17404102330       |
| iterators_row            | 727336166        | 8.28%        | 45110108412  | 11200622887  |  10003814921  | 1211890       | 3055467377        |
| filter_iterators_row     | 6379862229       | 13.41%       | 250544060670 | 63052966957  |  100023747197 | 1414666       | 17361396519       |

## Selecting columns
Convenient way to look at only some columns

### filter_row_select_gen

### filter_function_select_gen

## References
* [C++ Cache Friendly Data + Functional + Ranges = ❤️ - Björn Fahller - C++ on Sea 2024](https://www.youtube.com/watch?v=XJzs4kC9d-Y)
* [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc)
* [Data Storage in Entity Component Systems - Mathieu Ropert - Meeting C++ 2023](https://www.youtube.com/watch?v=b9hNKFj5R3Y)
* <https://github.com/rollbear/cache_functional_ranges>

