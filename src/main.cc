#include <fmt\core.h>

#include <exception>
#include <iostream>
#include <vector>

#include "sum/sum.h"

/**
 * @brief a test class to test doxygen
 *
 */
class test {
 private:
 public:
  test(/* args */) = default;
  ~test() = default;
};

/**
 * @brief a test function to test doxygen
 *
 * @param oka
 * @param notok
 * @return float
 */
auto func(int oka, int notok) -> float {
  return static_cast<float>(oka + notok);
}

auto add(int num1, int num2) -> float {
  return static_cast<float>(num1 + num2);
}

auto main(/* int argc, char const* argv[] */) -> int {
  const int COUNT = 5;
  fmt::print("Hello World\n");
  const int NUM = 77;
  if (NUM > COUNT) {
    fmt::print("count\n");
  } else {
    fmt::print("count1\n");
  }

  std::vector<int> test;

  try {  // initialising vector might cause an exception
    for (int i = 0; i < COUNT; i++) {
      int input = 0;
      std::cin >> input;
      test.push_back(input);
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (auto&& isn : test) {
    fmt::print("{}", isn);
  }

  fmt::print("{}", func(1, 2));
  fmt::print("{}", add(1, 2));
  fmt::print("{}", sum::sum(1, 2));

  fmt::print("NOPe");

  return 0;
}
