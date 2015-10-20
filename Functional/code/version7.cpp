#include <iostream>
#include <iterator>
#include <type_traits>

template <class T>
class FibonacciIterator : public std::iterator<std::input_iterator_tag, T> {
public:
  FibonacciIterator() {
    static_assert(std::is_integral<T>::value, "Integral type required");
    mCurrent = 0;
    mFirst = 0;
    mSecond = 1;
  }

  T operator*() const { return mCurrent; }

  FibonacciIterator &operator++() {
    mCurrent = mFirst + mSecond;
    mFirst = mSecond;
    mSecond = mCurrent;
    return *this;
  }

  FibonacciIterator &operator++(int) {
    auto temp = *this;
    operator++();
    return temp;
  }

  bool operator==(const FibonacciIterator &fIt) const {
    return mFirst == fIt.mFirst && mSecond == fIt.mSecond &&
           mCurrent == fIt.mCurrent;
  }

  bool operator!=(const FibonacciIterator &fIt) const {
    return !(*this == fIt);
  }

  bool operator<(const FibonacciIterator &fIt) const {
    return mFirst < fIt.mFirst && mSecond < fIt.mSecond &&
           mCurrent < fIt.mCurrent;
  }

private:
  T mFirst;
  T mSecond;
  T mCurrent;
};

int main() {
  FibonacciIterator<int> fib;
  for (int i = 0; i < 10; ++i) {
    std::cout << "Term " << i << " of the Fibonacci series: " << *(++fib)
              << std::endl;
  }
}
