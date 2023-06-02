# This is the test dir CMakeLists.txt, what should you do in here?
# add test targets
# add link libraries and include directories for all your targets
# add sources from current dir (not subdirs)

###########################################
### Required packages
###########################################
find_package(GTest CONFIG REQUIRED)

###########################################
### cmake-init tests
###########################################
add_executable(tests)
set_target_properties(
  tests
  PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# CMAKE_CURRENT_BINARY_DIR for tests is build/tests/

target_link_libraries(tests PRIVATE GTest::gtest_main)
target_link_libraries(tests PRIVATE coverage_options)
target_link_libraries(tests PRIVATE lib)
target_include_directories(tests PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

###########################################
### sources from current dir
###########################################s
target_sources(tests PRIVATE main_test.cc cmake_init_test.cc)

###########################################
### cmake-init cli_tests
###########################################
add_executable(cli_tests)
set_target_properties(
  cli_tests
  PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# CMAKE_CURRENT_BINARY_DIR for tests is build/tests/

target_link_libraries(cli_tests PRIVATE GTest::gtest_main)
target_link_libraries(cli_tests PRIVATE coverage_options)
target_link_libraries(cli_tests PRIVATE cli)
target_include_directories(cli_tests PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

###########################################
### sources from current dir
###########################################s
target_sources(cli_tests PRIVATE cli_test.cc)

###########################################
### sources from subdirs
###########################################s
add_subdirectory(cmake_init)

include(GoogleTest)
gtest_discover_tests(tests)
gtest_discover_tests(cli_tests)
