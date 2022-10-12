#include "cmake_init_lib.h"

auto main() -> int {
  cmake_init::CmakeInit cmake_init;
  cmake_init.Greet();
  return 0;
}
