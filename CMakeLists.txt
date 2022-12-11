cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

#####################################################
### Target (building app? a library? both?)
#####################################################
add_library(cmake-init_lib)
set_target_properties(cmake-init_lib PROPERTIES OUTPUT_NAME cmake-init
)# libcmake-init.a
# please add all your public headers to your targets here
target_sources(cmake-init_lib
               PRIVATE ${CMAKE_INIT_PUBLIC_HEADER_DIR}/cmake_init_lib.h)

add_executable(cmake-init_app)
set_target_properties(cmake-init_app PROPERTIES OUTPUT_NAME cmake-init
)# cmake-init.exe

#####################################################
### Source files
#####################################################
add_subdirectory(src)
