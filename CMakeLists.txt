cmake_minimum_required(VERSION 3.23)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

add_executable(cmake-init src/main.cc src/main2.cc)
target_link_libraries(cmake-init PRIVATE project_compile_options)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(cmake-init PRIVATE fmt::fmt)
