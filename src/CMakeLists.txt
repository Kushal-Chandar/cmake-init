###########################################
### Required packages
###########################################
find_package(fmt CONFIG REQUIRED)

###########################################
### cmake-init library
###########################################
target_sources(
  cmake_init_lib
  PRIVATE ${CMAKE_INIT_PUBLIC_HEADER_DIR}/cmake_init_lib.h
          ${CMAKE_INIT_IMPL_DIR}/cmake_init_lib.cc
          ${CMAKE_INIT_PRIVATE_HEADER_DIR}/cmake_init_lib/print_greeting.h
          ${CMAKE_INIT_IMPL_DIR}/cmake_init_lib/print_greeting.cc)
target_link_libraries(cmake_init_lib PRIVATE project_compile_options)
target_link_libraries(cmake_init_lib PRIVATE fmt::fmt)

target_include_directories(
  cmake_init_lib PUBLIC $<BUILD_INTERFACE:${CMAKE_INIT_PUBLIC_HEADER_DIR}>
                        $<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
# you can include header files "cmake_init_lib.h"
# your library users must use  "cmake-init/cmake_init_lib.h"

target_include_directories(cmake_init_lib
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})
# a target linking to this library doesnot need to have "include" in its target_include_libraries if set public

###########################################
### cmake-init
###########################################
target_sources(cmake_init_app PRIVATE ${CMAKE_INIT_IMPL_DIR}/main.cc)
target_link_libraries(cmake_init_app PRIVATE fmt::fmt)
target_link_libraries(cmake_init_app PRIVATE configuration_header
)# Enable configuration header option should be set to on
target_link_libraries(cmake_init_app PRIVATE project_compile_options)
target_link_libraries(cmake_init_app PRIVATE cmake_init_lib)
target_include_directories(cmake_init_app PRIVATE ${CMAKE_INIT_SOURCE_DIR})
target_include_directories(cmake_init_app
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})
