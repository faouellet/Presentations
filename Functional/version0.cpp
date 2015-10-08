#include <iostream>

int fibonacci(int i)
{
    if (i < 2)
        return i;

    return fibonacci(i - 1) + fibonacci(i - 2);
}

/*int main()
{
    std::cout << "10th Fibonacci number: " << fibonacci(10) << std::endl;
}*/
