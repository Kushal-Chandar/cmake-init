cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

#####################################################
### Target (building app? a library? both?)
#####################################################
add_library(cmake_init_lib)
set_target_properties(cmake_init_lib PROPERTIES OUTPUT_NAME cmake-init
)# libcmake-init.a

add_executable(cmake_init_app)
set_target_properties(cmake_init_app PROPERTIES OUTPUT_NAME cmake-init
)# cmake-init.exe

#####################################################
### Source files to build
#####################################################
add_subdirectory(src)
