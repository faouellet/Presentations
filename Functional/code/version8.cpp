#include <iostream>
#include <iterator>
#include <type_traits>

template <class T, class F>
class GeneratorIterator : public std::iterator<std::input_iterator_tag, T> {
public:
  explicit GeneratorIterator(F &&f) : mFunc{ f }, mCurrentVal{ T{} } {}

  T operator*() const { return mCurrentVal; }

  GeneratorIterator &operator++() {
    mCurrentVal = mFunc();
    return *this;
  }

  GeneratorIterator &operator++(int) {
    auto temp = *this;
    operator++();
    return *this;
  }

  bool operator==(const GeneratorIterator &fIt) const {
    return mCurrentVal == fIt.mCurrentVal && mFunc == fIt.mFunc;
  }

  bool operator!=(const GeneratorIterator &fIt) const {
    return !(*this == fIt);
  }

  bool operator<(const GeneratorIterator &fIt) const {
    return mCurrentVal < fIt.mCurrentVal;
  }

private:
  F mFunc;
  T mCurrentVal;
};

template <class F, class T = typename std::result_of<F()>::type>
auto make_generator(F &&f) {
  return GeneratorIterator<T, F>(f);
}

int main() {
  auto fibonacci = [ current = 0, first = 0, second = 1 ]() mutable {
    current = first + second;
    first = second;
    second = current;
    return current;
  };
  auto sqr = [](int x) { return x * x; };
  auto func = [&]() { return sqr(fibonacci()); };

  auto gen = make_generator(func);
  for (int i = 0; i < 10; ++i) {
    std::cout << *(++gen) << std::endl;
  }
}
