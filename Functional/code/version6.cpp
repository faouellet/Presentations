#include <functional>
#include <iostream>

template <class L1, class L2> auto operator|(L1 l1, L2 l2) {
  return [l1, l2](auto... x) { return l1(l2(x...)); };
}

int main() {
  auto sqr = [](int x) { return x * x; };
  std::function<int(int)> fibonacci = [&](int i) {
    if (i < 2)
      return i;

    return fibonacci(i - 1) + fibonacci(i - 2);
  };

  std::cout << sqr(fibonacci(10)) << std::endl;
}
