#include "cmake-init/cmake_init_lib.h"
#include "configuration/config.h"
#include "fmt/color.h"

auto main() -> int {
  cmake_init::CmakeInit cmake_init;
  cmake_init.Greet();
  fmt::print("{}\n{}\n{}\n", cmake_init::config::git_sha,
             cmake_init::config::project_name,
             cmake_init::config::project_version);
  return 0;
}
