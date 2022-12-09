#include "cmake-init/cmake_init_lib.h"

#include <fmt/core.h>

#include <string_view>

#include "cmake_init_lib/print_greeting.h"

namespace cmake_init {

CmakeInit::CmakeInit(std::string_view message) : message_(message) {}

auto CmakeInit::Greet() -> void {
  fmt::print("{}\n", message_);
  cmake_init_lib::PrintGreeting print_greeting(
      std::string_view("Created print_greeting oject"));
  print_greeting.Print();
}

auto sum_of_first_n_naturals(int num) -> int {
  int sum = 0;
  for (int i = 1; i <= num; sum += i, i++) {
    ;
  }
  return sum;
}

}  // namespace cmake_init
