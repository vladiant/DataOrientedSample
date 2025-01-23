#include <array>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>

#include "input_data.hpp"
template <size_t I, typename T, typename... Ts>
struct nth_type {
  using type = typename nth_type<I - 1, Ts...>::type;
};

template <typename T, typename... Ts>
struct nth_type<0, T, Ts...> {
  using type = T;
};

template <size_t I, typename... Ts>
using nth_type_t = typename nth_type<I, Ts...>::type;

template <typename...>
struct table;

template <typename, typename>
struct row;

template <typename... Ts, size_t... Cs>
struct row<table<Ts...>, std::index_sequence<Cs...>> {
  using row_id = typename table<Ts...>::row_id;
  row(table<Ts...>* tab, size_t offs) : t(tab), offset(offs) {}
  template <size_t... Is>
  row(const row<table<Ts...>, std::index_sequence<Is...>>& r)
      : t(r.t), offset(r.offset) {}
  row_id id() const { return t->reverse_index_[offset]; }
  template <size_t I>
  friend auto& get(const row& r) {
    static constexpr std::array columns{Cs...};
    return std::get<columns[I]>(r.t->data_)[r.offset];
  }
  table<Ts...>* t;
  size_t offset;
};

template <typename Table, size_t... Cs>
struct std::tuple_size<row<Table, std::index_sequence<Cs...>>>
    : std::integral_constant<size_t, sizeof...(Cs)> {};

template <size_t I, typename... Ts, size_t... Cs>
struct std::tuple_element<I, row<table<Ts...>, std::index_sequence<Cs...>>> {
  static constexpr std::array indexes = {Cs...};
  using type = nth_type_t<indexes[I], Ts...>&;
};

template <typename... Ts>
class table {
  using indexes = std::index_sequence_for<Ts...>;

 public:
  using row = ::row<table, indexes>;
  template <typename, typename>
  friend class ::row;
  struct row_id {
    size_t offset;
  };
  struct sentinel {};
  struct iterator {
    using value_type = row;
    using difference_type = ssize_t;

    value_type operator*() const { return {t, offset}; }
    iterator& operator++() {
      ++offset;
      return *this;
    }
    iterator operator++(int) {
      auto copy = *this;
      ++*this;
      return copy;
    }
    bool operator==(const iterator&) const = default;
    bool operator==(sentinel) const { return offset == t->size(); }
    table* t;
    size_t offset;
  };
  friend class iterator;
  iterator begin() { return {this, 0}; }
  sentinel end() const { return {}; }
  row_id insert(Ts... ts) {
    row_id data_offset{size()};
    auto values = std::forward_as_tuple(ts...);
    std::invoke(
        [&]<size_t... Is>(std::index_sequence<Is...>) {
          (std::get<Is>(data_).push_back(std::get<Is>(values)), ...);
        },
        indexes{});
    if (first_free_.offset == index_.size()) {
      reverse_index_.push_back(first_free_);
      index_.push_back(data_offset);
      first_free_.offset = index_.size();
      return data_offset;
    } else {
      auto new_pos = std::exchange(first_free_, index_[first_free_.offset]);
      index_[new_pos.offset] = data_offset;
      reverse_index_.push_back(new_pos);
      return new_pos;
    }
  }
  void erase(iterator i) {
    auto data_offset = i.offset;
    auto id = reverse_index_[data_offset];
    auto assign_from_last_and_pop_back = [this, data_offset](auto i) {
      auto& vec = std::get<i.value>(data_);
      vec[data_offset] = vec.back();
      vec.pop_back();
    };
    auto move_last = [&]<size_t... Is>(std::index_sequence<Is...>) {
      (assign_from_last_and_pop_back(std::integral_constant<size_t, Is>{}),
       ...);
    };
    std::invoke(move_last, indexes{});
    if (data_offset != reverse_index_.size() - 1) {
      reverse_index_[data_offset] = reverse_index_.back();
      index_[reverse_index_[data_offset].offset].offset = data_offset;
    }
    reverse_index_.pop_back();
    index_[id.offset] = first_free_;
    first_free_ = id;
  }
  void erase(row_id id) {
    auto data_offset = index_[id.offset].offset;
    erase(iterator{this, data_offset});
  }

  row operator[](row_id id) {
    auto offset = index_[id.offset].offset;
    return {this, offset};
  }
  bool has_row(row_id id) const {
    if (id.offset >= index_.size()) {
      return false;
    }
    auto offset = index_[id.offset].offset;
    if (offset >= reverse_index_.size()) {
      return false;
    }
    return reverse_index_[offset].offset == id.offset;
  }
  void reserve(size_t size) {
    std::invoke(
        [&]<size_t... Is>(std::index_sequence<Is...>) {
          (std::get<Is>(data_).reserve(size), ...);
        },
        indexes{});
  }

  size_t size() const { return std::get<0>(data_).size(); }
  bool empty() const { return size() == 0; }

 public:
  std::tuple<std::vector<Ts>...> data_;
  std::vector<row_id> reverse_index_;
  std::vector<row_id> index_;
  row_id first_free_ = {0};
};
template <size_t... Is, typename Table, size_t... Cs>
auto select(const row<Table, std::index_sequence<Cs...>>& r) {
  static constexpr size_t columns[]{Cs...};
  return row<Table, std::index_sequence<columns[Is]...>>(r);
}

template <typename R, size_t... Cs>
struct range_selector {
  using r_iterator = decltype(std::declval<R&>().begin());
  struct iterator : r_iterator {
    using difference_type = ssize_t;
    using value_type = decltype(select<Cs...>(*std::declval<r_iterator>()));

    iterator(const r_iterator& i) : r_iterator(i) {}
    auto operator*() const {
      const r_iterator& i = *this;
      return select<Cs...>(*i);
    }
  };
  iterator begin() { return iterator{r.begin()}; }
  auto end() { return r.end(); }
  R& r;
};

template <size_t... Cs>
struct range_selector_maker {
  template <typename R>
  friend range_selector<R, Cs...> operator|(R& r, range_selector_maker) {
    return {r};
  }
};

template <size_t... Cs>
range_selector_maker<Cs...> select() {
  return {};
}

template <typename>
inline constexpr bool row_type_v = false;

template <typename T, typename Cs>
inline constexpr bool row_type_v<row<T, Cs>> = true;

template <typename T>
concept row_type = row_type_v<T>;

template <size_t... Cs, typename F>
auto select(F&& f) requires(!row_type<std::remove_cvref_t<F>>) {
  return [f = std::forward<F>(f)]<typename T, typename Is>(row<T, Is> r) {
    return f(select<Cs...>(r));
  };
}

template <typename F>
auto apply(F&& f) {
  return [f = std::forward<F>(f)]<row_type R>(R r) {
    return std::invoke(
        [&]<size_t... Cs>(std::index_sequence<Cs...>) {
          return f(get<Cs>(r)...);
        },
        std::make_index_sequence<std::tuple_size_v<R>>{});
  };
}

int main() {
  table<int, int, int, int> values;
  values.reserve(end_data() - begin_data());
  for (const auto* p = begin_data(); p != end_data(); ++p) {
    values.insert(p->x, p->y, p->z, p->d);
  }

  int start = 0;
  while (start < 50000) {
    auto predicate = [&](int z, int d) { return d == start && z == 1; };
    auto found_values =
        values | std::ranges::views::filter(select<2, 3>(apply(predicate)));
    for (auto [x, d] : found_values | select<0, 3>()) {
      std::cout << "d=" << d << " x=" << x << '\n';
    }
    start += 1;
  }
}
