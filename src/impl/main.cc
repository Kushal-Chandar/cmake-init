#include <fmt/core.h>

#include <string_view>

#include "cmake_init_lib.h"
#include "configuration/config.h"

auto main() -> int {
  cmake_init::CmakeInit cmake_init(
      std::string_view("Creating cmake_init object"));
  cmake_init.Greet();
  fmt::print("{}\n{}\n{}\n", cmake_init::config::git_sha,
             cmake_init::config::project_name,
             cmake_init::config::project_version);
  return 0;
}
