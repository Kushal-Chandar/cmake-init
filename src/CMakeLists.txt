# This is the source dir CMakeLists.txt add link libraries and include directories for all your targets here

###########################################
### Required packages
###########################################
find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

###########################################
### cmake-init library
###########################################
target_link_libraries(cmake-init_lib PRIVATE project_compile_options)
target_link_libraries(cmake-init_lib PRIVATE fmt::fmt)

target_include_directories(
  cmake-init_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_INIT_PUBLIC_HEADER_DIR}>
                        $<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
# you can include header files "cmake_init_lib.h" but
# your library users must use  "cmake-init/cmake_init_lib.h"

target_include_directories(cmake-init_lib
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})
# a target linking to this library doesnot need to have "include" in its target_include_libraries if set public

###########################################
### cmake-init
###########################################
target_link_libraries(cmake-init_app PRIVATE fmt::fmt)
target_link_libraries(cmake-init_app PRIVATE CLI11::CLI11)
target_link_libraries(cmake-init_app PRIVATE configuration_header
)# Enable configuration header option should be set to on
target_link_libraries(cmake-init_app PRIVATE project_compile_options)
target_link_libraries(cmake-init_app PRIVATE cmake-init_lib)
target_include_directories(cmake-init_app
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

#####################################################
### Source files in IMPL, INC
#####################################################
add_subdirectory(impl)
add_subdirectory(inc)
