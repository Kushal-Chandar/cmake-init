cmake_minimum_required(VERSION 3.24)

project(cmake-init LANGUAGES CXX)

include(cmake/init.cmake)

# This is the root level CMakeLists.txt, what should you do here?
# add primary and global targets for your project
# add your public header files to requrired targets here

#############################################################
### Target (building app? a library? both?)
#############################################################
add_library(lib)
set_target_properties(lib PROPERTIES OUTPUT_NAME cmake-init) # libcmake-init.a

# please add all your public headers to your targets here
target_sources(lib PRIVATE ${CMAKE_INIT_PUBLIC_HEADER_DIR}/cmake_init.h)

add_executable(app)
set_target_properties(app PROPERTIES OUTPUT_NAME cmake-init) # cmake-init.exe

#############################################################
### Source files
#############################################################
add_subdirectory(src)
