cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

#####################################################
### Target (building app? a library? both?)
#####################################################
add_library(cmake_init_lib)
add_executable(cmake_init)

#####################################################
### Source files to build
#####################################################
add_subdirectory(src)
