#include "cmake_init_lib/print_greeting.h"

#include <fmt/color.h>
#include <fmt/core.h>

namespace cmake_init::cmake_init_lib {
auto PrintGreeting::Print() -> bool {
  fmt::print(fg(fmt::color::green),
             "Hello\n"
             "This sample program is to demonstrate directory and namespace "
             "structure.\n");
  fmt::print(fg(fmt::color::yellow),
             "Notice 💀💀💀💀💀\n"
             "The root level name space is directly in the include directory.\n"
             "Nested namespaces are extended as per requirement.\n");
  return true;
}
}  // namespace cmake_init::cmake_init_lib
