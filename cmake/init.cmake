include_guard()

option(UPDATE_VCPKG "Install or update vcpkg in the project root directory" OFF)
option(MANIFEST_FEATURE_TEST "Get packages required for testing" OFF)
option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(CODE_COVERAGE "Enable coverage reporting" OFF)
option(BUILD_TESTING "Build the testing tree" OFF)
option(ENABLE_DOXYGEN "Build doxygen docs" OFF)
option(ENABLE_CCACHE "Enable ccache for faster compilation" OFF)
option(ENABLE_IPO "Enable IPO/LTO, for improved runtime performance" OFF)
option(SANITIZE_ADDRESS "Enable sanitizer for address" OFF)
option(SANITIZE_UNDEFINED "Enable sanitizer for undefined behaviour" OFF)

# ----------------------------------------------------------------------------
#   Get all options set from options.cmake
# ----------------------------------------------------------------------------
include(${CMAKE_CURRENT_SOURCE_DIR}/options.cmake)

# ----------------------------------------------------------------------------
#   An interface library containing all compile options
# ----------------------------------------------------------------------------
add_library(project_compile_options INTERFACE)

# ----------------------------------------------------------------------------
#   Get absolute path with symlinks resolved
# ----------------------------------------------------------------------------
file(REAL_PATH "${CMAKE_CURRENT_BINARY_DIR}" BINARY_DIR)
file(REAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}" SOURCE_DIR)

# ----------------------------------------------------------------------------
#   Prevent building in source directory
# ----------------------------------------------------------------------------
if("${SOURCE_DIR}" STREQUAL "${BINARY_DIR}")
  message("# ---------------------------------------------------------")
  message("#   Warning: build directory and source directory are same.")
  message("# ---------------------------------------------------------")
  message(FATAL_ERROR "In source build.")
endif()

# ----------------------------------------------------------------------------
#   Project configuration
# ----------------------------------------------------------------------------

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------------
#   Link time optimizations
# ----------------------------------------------------------------------------
if(ENABLE_IPO)
  if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL
                                            "RelWithDebInfo")
    include(CheckIPOSupported)
    check_ipo_supported(RESULT result OUTPUT output)
    if(result)
      set(CMAKE_INTERPROCEDURAL_OPTIMIZATION
          ON
          PARENT_SCOPE)
    else()
      message(STATUS "IPO is not supported: ${output}")
    endif()
  endif()
endif()

# ----------------------------------------------------------------------------
#   Use -std=c++17 instead of -std=gnu++17 (Disable gnu specific features)
# ----------------------------------------------------------------------------
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------------------------------------
#   Dependency graph visualization
# ----------------------------------------------------------------------------
set(GRAPHVIZ_CUSTOM_TARGETS TRUE)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/graphviz)
add_custom_target(
  graphviz
  COMMAND ${CMAKE_COMMAND} "--graphviz=graphviz/dependency.dot" .
  COMMAND dot -Tsvg graphviz/dependency.dot -o graphviz/dependency.svg
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

# ----------------------------------------------------------------------------
#   Call other scripts (calling from source directory cmake file, 'cmake' is required)
# ----------------------------------------------------------------------------
include(cmake/ccache.cmake)
include(cmake/compiler_warnings.cmake)
include(cmake/sanitizers.cmake)
include(cmake/static_analysis.cmake)
include(cmake/vcpkg.cmake)
include(cmake/doxygen.cmake)
include(cmake/testing.cmake)
