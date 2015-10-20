#include <iostream>

int main() {
  auto fibonacci = [ current = 0, first = 0, second = 1 ](int i) mutable {
    while (i > 1) {
      current = first + second;
      first = second;
      second = current;
      --i;
    }
    return current;
  };

  std::cout << "10th Fibonacci number: " << fibonacci(10) << std::endl;

  return 0;
}
