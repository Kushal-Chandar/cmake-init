#if !defined(CMAKE_INIT_SRC_INC_CLI_H_)
#define CMAKE_INIT_SRC_INC_CLI_H_

#include <optional>

namespace cmake_init {

class CLI {
 public:
  auto parse(int argc, char const *argv[]) noexcept -> std::optional<int>;
};

}  // namespace cmake_init

#endif  // CMAKE_INIT_SRC_INC_CLI_H_
