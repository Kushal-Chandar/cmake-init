#include "cmake_init_lib.h"

#include "cmake_init_lib/print_greeting.h"

namespace cmake_init {
auto CmakeInit::Greet() -> void {
  cmake_init_lib::PrintGreeting print_greeting;
  print_greeting.Print();
}

}  // namespace cmake_init
