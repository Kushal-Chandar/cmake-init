#if !defined(CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_)
#define CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_

#include <string_view>

namespace cmake_init {

auto sum_of_first_n_naturals(int num) -> int;

class CmakeInit {
 public:
  auto Greet() -> void;
  explicit CmakeInit(std::string_view);

 private:
  std::string_view message_;
};

}  // namespace cmake_init

#endif  // CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_
