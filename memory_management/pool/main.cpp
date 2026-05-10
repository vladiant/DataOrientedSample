#include <algorithm>
#include <iostream>
#include <memory>

template <typename T>
class Pool {
  struct FreeNode {
    FreeNode* next;
  };

  static constexpr size_t SLOT_SIZE = std::max(sizeof(T), sizeof(FreeNode*));

  uint8_t* m_buffer = nullptr;
  size_t m_capacity = 0;
  FreeNode* m_free_list = nullptr;

 public:
  explicit Pool(size_t count) {
    m_capacity = count;
    m_buffer = new uint8_t[count * SLOT_SIZE];

    for (size_t i = 0; i < count; ++i) {
      auto* node = reinterpret_cast<FreeNode*>(m_buffer + i * SLOT_SIZE);
      node->next = m_free_list;
      m_free_list = node;
    }
  }

  ~Pool() { delete[] m_buffer; }

  T* allocate() {
    if (!m_free_list) return nullptr;

    void* ptr = m_free_list;
    m_free_list = m_free_list->next;
    return static_cast<T*>(ptr);
  }

  void deallocate(T* ptr) {
    if (!ptr) return;
    auto* node = reinterpret_cast<FreeNode*>(ptr);
    node->next = m_free_list;
    m_free_list = node;
  }

  template <typename... Args>
  T* create(Args&&... args) {
    T* ptr = allocate();
    if (ptr) return new (ptr) T(std::forward<Args>(args)...);
    return nullptr;
  }

  void destroy(T* ptr) {
    if (ptr) {
      ptr->~T();
      deallocate(ptr);
    }
  }
};

int main() {
  Pool<int> int_pool(10);

  int* val = int_pool.create(42);
  if (val) {
    std::cout << "Allocated int: " << *val
              << " (Slot size: " << std::max(sizeof(int), sizeof(void*))
              << " bytes)\n";
    int_pool.destroy(val);
  }

  return 0;
}
