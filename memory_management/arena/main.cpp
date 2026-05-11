#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

class Arena {
  uint8_t* m_buffer;
  size_t m_capacity;
  size_t m_offset = 0;

 public:
  explicit Arena(size_t capacity)
      : m_buffer(new uint8_t[capacity]), m_capacity(capacity) {}
  ~Arena() { delete[] m_buffer; }
  Arena(const Arena&) = delete;

  void* allocate(size_t size, size_t alignment = alignof(std::max_align_t)) {
    size_t aligned_offset = (m_offset + alignment - 1) & ~(alignment - 1);
    if (aligned_offset + size > m_capacity) return nullptr;
    void* ptr = m_buffer + aligned_offset;
    m_offset = aligned_offset + size;
    return ptr;
  }
  void reset() { m_offset = 0; }
};

template <typename T>
struct ArenaAllocator {
  using value_type = T;
  Arena& arena;

  explicit ArenaAllocator(Arena& a) : arena(a) {}

  template <typename U>
  ArenaAllocator(const ArenaAllocator<U>& other) : arena(other.arena) {}

  T* allocate(std::size_t n) {
    void* ptr = arena.allocate(n * sizeof(T), alignof(T));
    if (!ptr) throw std::bad_alloc();
    return static_cast<T*>(ptr);
  }

  void deallocate(T*, std::size_t) noexcept {}
};

int main() {
  Arena my_arena(1024);  // 1KB

  ArenaAllocator<int> alloc(my_arena);

  std::vector<int, ArenaAllocator<int>> vec(alloc);

  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  for (int n : vec) std::cout << n << " ";  // Output: 10 20 30

  return 0;
}
