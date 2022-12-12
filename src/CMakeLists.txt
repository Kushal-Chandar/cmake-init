# This is the source dir CMakeLists.txt, what should you do in here?
# add non-primary / sub-targets
# add link libraries and include directories for all your targets

###########################################
### Required packages
###########################################
find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

###########################################
### Sub targets
###########################################
#-----------------------------------------
# cli
#-----------------------------------------
add_library(cli)
target_link_libraries(cli PRIVATE CLI11::CLI11)
target_link_libraries(cli PRIVATE fmt::fmt)
target_link_libraries(cli PRIVATE configuration_header
)# Enable configuration header option should be set to on
target_link_libraries(cli PRIVATE project_compile_options)
target_include_directories(cli PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

###########################################
### cmake-init library
###########################################
target_link_libraries(lib PRIVATE project_compile_options)
target_link_libraries(lib PRIVATE fmt::fmt)
target_include_directories(
  lib PUBLIC $<BUILD_INTERFACE:${CMAKE_INIT_PUBLIC_HEADER_DIR}>
             $<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
# you can include header files "cmake_init.h" but
# your library users must use  "cmake-init/cmake_init.h"

target_include_directories(lib PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

###########################################
### cmake-init app
###########################################
target_link_libraries(app PRIVATE project_compile_options)
target_link_libraries(app PRIVATE cli)
target_link_libraries(app PRIVATE lib)
target_include_directories(app PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

#####################################################
### Source files in IMPL, INC
#####################################################
add_subdirectory(impl)
add_subdirectory(inc)
