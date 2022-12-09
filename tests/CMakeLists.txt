###########################################
### Required packages
###########################################
find_package(GTest CONFIG REQUIRED)

###########################################
### cmake-init tests
###########################################
add_executable(cmake-init_tests)
target_sources(
  cmake-init_tests
  PRIVATE ${CMAKE_INIT_TEST_DIR}/main_test.cc
          ${CMAKE_INIT_TEST_DIR}/cmake_init_lib_test.cc
          ${CMAKE_INIT_TEST_DIR}/cmake_init_lib/print_greeting_test.cc)
set_target_properties(
  cmake-init_tests
  PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# CMAKE_CURRENT_BINARY_DIR for tests is build/tests/

target_link_libraries(cmake-init_tests PRIVATE GTest::gtest_main)
target_link_libraries(cmake-init_tests PRIVATE coverage_options)
target_link_libraries(cmake-init_tests PRIVATE cmake-init_lib)
target_include_directories(cmake-init_tests
                           PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})
# add you libs (can propagate target to sub dir?)
include(GoogleTest)
gtest_discover_tests(cmake-init_tests)
