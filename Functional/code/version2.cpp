#include <functional>
#include <iostream>
#include <unordered_map>

int main() {
  std::function<int(int)> fibonacci = [&](int i) mutable {
    static std::unordered_map<int, int> cache = { { 0, 0 }, { 1, 1 } };

    if (cache.find(i) == cache.end())
      cache[i] = fibonacci(i - 1) + fibonacci(i - 2);

    return cache[i];
  };

  std::cout << "10th Fibonacci number: " << fibonacci(10) << std::endl;
}
