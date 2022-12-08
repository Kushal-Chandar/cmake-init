###########################################
### Required packages
###########################################
find_package(fmt CONFIG REQUIRED)

###########################################
### cmake-init library
###########################################
target_sources(
  cmake_init_lib
  PRIVATE ${PROJECT_SOURCE_DIR}/include/cmake-init/cmake_init_lib.h
          ${CMAKE_CURRENT_LIST_DIR}/impl/cmake_init_lib.cc)
set_target_properties(cmake_init_lib PROPERTIES OUTPUT_NAME cmake-init)
target_link_libraries(cmake_init_lib PRIVATE project_compile_options)
target_link_libraries(cmake_init_lib PRIVATE fmt::fmt)
target_include_directories(cmake_init_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(cmake_init_lib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/inc)
# a target linking to this library doesnot need to have "include" in its target_include_libraries if set public

# ${CMAKE_CURRENT_LIST_DIR}/inc/cmake_init_lib/print_greeting.h
# ${CMAKE_CURRENT_LIST_DIR}/impl/cmake_init_lib/print_greeting.cc

###########################################
### cmake-init
###########################################
set_target_properties(cmake_init PROPERTIES OUTPUT_NAME cmake-init)
target_sources(cmake_init PRIVATE impl/main.cc)
target_link_libraries(cmake_init PRIVATE fmt::fmt)
target_link_libraries(cmake_init PRIVATE configuration_header
)# Enable configuration header option should be set to on
target_link_libraries(cmake_init PRIVATE project_compile_options)
target_link_libraries(cmake_init PRIVATE cmake_init_lib)
target_include_directories(cmake_init PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(cmake_init PRIVATE ${CMAKE_CURRENT_LIST_DIR}/inc)
