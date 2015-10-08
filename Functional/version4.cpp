#include <iostream>

constexpr int fibonnaci(int i)
{
    if (i < 2)
        return i;

    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main()
{
    std::cout << fibonnaci(10) << std::endl;
}
