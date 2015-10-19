#include <iostream>

constexpr int sqr(int val) { return val * val; }

constexpr int fibonacci(int i) {
  if (i < 2)
    return i;

  return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() { std::cout << sqr(fibonacci(10)) << std::endl; }
