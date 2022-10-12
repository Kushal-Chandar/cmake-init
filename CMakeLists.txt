cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

add_library(cmake_init_lib STATIC)
target_sources(
  cmake_init_lib
  PRIVATE include/cmake_init_lib.h
          src/cmake_init_lib.cc
          include/cmake_init_lib/print_greeting.h
          src/cmake_init_lib/print_greeting.cc)
target_link_libraries(cmake_init_lib PRIVATE project_compile_options)
target_include_directories(cmake_init_lib PUBLIC include)
# a target linking to this library doesnot need to have its includes in its target include libraries

find_package(fmt CONFIG REQUIRED)
target_link_libraries(cmake_init_lib PRIVATE fmt::fmt)

add_executable(cmake-init)
target_sources(cmake-init PRIVATE src/main.cc)
target_link_libraries(cmake-init PRIVATE project_compile_options)
target_link_libraries(cmake-init PRIVATE cmake_init_lib)

