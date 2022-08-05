cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

add_library(sum STATIC)
target_sources(sum PRIVATE src/sum/sum.cc include/sum/sum.h)
target_link_libraries(sum PRIVATE project_compile_options)
target_include_directories(sum PUBLIC include)
# a target linking to this library doesnot need to have its includes in its target include libraries

add_executable(cmake-init)
target_sources(cmake-init PRIVATE src/main.cc)
target_link_libraries(cmake-init PRIVATE project_compile_options)
target_link_libraries(cmake-init PRIVATE sum)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(cmake-init PRIVATE fmt::fmt)
