#include <iostream>

template <int Val>
struct Sqr
{
    static const int value = Val * Val;
};

template <int Val>
struct Fib
{
    static const int value = Fib<Val - 1>::value + Fib<Val - 2>::value;
};

template <>
struct Fib<0>
{
    static const int value = 0;
};

template <>
struct Fib<1>
{
    static const int value = 1;
};

/*int main()
{
    std::cout << Sqr<Fib<10>::value>::value << std::endl;
}*/