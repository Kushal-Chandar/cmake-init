#include "cmake_init_lib.h"

#include "cmake_init_lib/print_greeting.h"

namespace cmake_init {

auto CmakeInit::Greet() -> void {
  cmake_init_lib::PrintGreeting print_greeting;
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
