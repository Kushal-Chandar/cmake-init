#if !defined(CMAKE_INIT_SRC_INC_CMAKE_INIT_LIB_PRINT_GREETING_H_)
#define CMAKE_INIT_SRC_INC_CMAKE_INIT_LIB_PRINT_GREETING_H_

#include <string_view>

namespace cmake_init::cmake_init_lib {
class PrintGreeting {
 public:
  auto Print() -> bool;
  PrintGreeting(std::string_view);

 private:
  std::string_view message_;
};
}  // namespace cmake_init::cmake_init_lib

#endif  // CMAKE_INIT_SRC_INC_CMAKE_INIT_LIB_PRINT_GREETING_H_
