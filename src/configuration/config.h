#ifndef CMAKE_INIT_SRC_CONFIGURATION_CONFIG_H_
#define CMAKE_INIT_SRC_CONFIGURATION_CONFIG_H_

// This is a configuration file which will be used to generate config.h file

#include<string_view>

namespace cmake_init::config {
inline constexpr std::string_view project_name = "cmake_init";
inline constexpr std::string_view project_version = "v0.0.2";
inline constexpr int project_version_major{0};
inline constexpr int project_version_minor{0};
inline constexpr int project_version_patch{2};
inline constexpr std::string_view git_sha = "099023f129ce1e29144211d3b05b7bdacda5ff86";
}  // namespace cmake_init::config

#endif  // CMAKE_INIT_SRC_CONFIGURATION_CONFIG_H_
