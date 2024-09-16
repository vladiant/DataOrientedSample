# Cache Friendly Data

```bash
sudo apt install linux-tools-common
sudo apt install linux-tools-5.15.0-121-generic
```

```bash
sudo perf stat -e cache-references,cache-misses,L1-dcache-prefetches,instructions,cpu-cycles,branches,branch-misses,duration_time ./vector_of_structs
```


## References
* [C++ Cache Friendly Data + Functional + Ranges = ❤️ - Björn Fahller - C++ on Sea 2024](https://www.youtube.com/watch?v=XJzs4kC9d-Y)
* [CppCon 2014: Mike Acton "Data-Oriented Design and C++"](https://www.youtube.com/watch?v=rX0ItVEVjHc)
* [Data Storage in Entity Component Systems - Mathieu Ropert - Meeting C++ 2023](https://www.youtube.com/watch?v=b9hNKFj5R3Y)
* <https://github.com/rollbear/cache_functional_ranges>

