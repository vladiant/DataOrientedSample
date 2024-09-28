#include <algorithm>
#include <random>
#include <vector>

struct object {
  int x;
  int y;
  int z;
  int d;
};

namespace {
constexpr size_t N = 1000000;
constexpr int kMaxValue = 100000;

std::random_device r;
std::mt19937 e{r()};
std::uniform_int_distribution n{0, kMaxValue};

object data[N];

template <typename D, typename G, size_t Size>
auto generate(D& d, G& g, object (&aData)[Size]) {
  std::for_each(std::begin(aData), std::end(aData), [&](auto& elem) {
    elem = object{d(g), d(g), d(g), d(g)};
  });
  return true;
}

auto init = generate(n, e, data);

auto begin_data() { return std::begin(data); }

auto end_data() { return std::end(data); }

}  // namespace

template <typename T, typename P>
void drop_if(std::vector<T>& v, P p) {
  size_t i = 0;
  while (i < v.size()) {
    if (p(v[i])) {
      v[i] = std::move(v.back());
      v.pop_back();
    } else {
      ++i;
    }
  }
}

int main() {
  std::vector<object> values(begin_data(), end_data());

  int start = 100;
  int iter = 0;
  while (!values.empty()) {
    drop_if(values, [&start](const auto& obj) { return obj.z < start; });
    ++iter;
    start += 10;
  }
  return iter;
}
