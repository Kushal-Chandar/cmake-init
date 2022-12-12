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
add_library(cmake-init_cli)
target_link_libraries(cmake-init_cli PRIVATE CLI11::CLI11)
target_link_libraries(cmake-init_cli PRIVATE fmt::fmt)
target_link_libraries(cmake-init_cli PRIVATE configuration_header
)# Enable configuration header option should be set to on
target_link_libraries(cmake-init_cli PRIVATE project_compile_options)
target_include_directories(cmake-init_cli
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

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

###########################################
### cmake-init app
###########################################
target_link_libraries(cmake-init_app PRIVATE project_compile_options)
target_link_libraries(cmake-init_app PRIVATE cmake-init_cli)
target_link_libraries(cmake-init_app PRIVATE cmake-init_lib)
target_include_directories(cmake-init_app
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

#####################################################
### Source files in IMPL, INC
#####################################################
add_subdirectory(impl)
add_subdirectory(inc)
