#include <iostream>

int main() {
  auto fibonacci = [ current = 0, first = 0, second = 1 ]() mutable {
    current = first + second;
    first = second;
    second = current;
    return current;
  };

  for (int i = 0; i < 10; ++i)
    std::cout << "Fibonacci number: " << fibonacci() << std::endl;

  return 0;
}
