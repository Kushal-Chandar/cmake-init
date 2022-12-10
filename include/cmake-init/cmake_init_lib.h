#if !defined(CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_)
#define CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_

#include <string_view>

namespace cmake_init {

auto sum_of_first_n_naturals(int num) noexcept -> int;

class CmakeInit {
 public:
  auto Greet() noexcept -> void;
  explicit CmakeInit(std::string_view) noexcept;

 private:
  std::string_view message_;
};

}  // namespace cmake_init

#endif  // CMAKE_INIT_INCLUDE_CMAKE_INIT_CMAKE_INIT_LIB_H_
