#include <string_view>

#include "cli.h"
#include "cmake_init.h"

auto main(int argc, char const *argv[]) -> int {
  auto optional = cmake_init::CLI::Parse(argc, argv);
  if (optional.has_value()) {
    return optional.value();
  }

  cmake_init::CmakeInit cmake_init(
      std::string_view("Creating cmake_init object"));
  cmake_init.Greet();

  return 0;
}
