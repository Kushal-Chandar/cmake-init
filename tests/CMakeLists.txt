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
target_link_libraries(tests PRIVATE cli)
target_include_directories(tests PRIVATE ${CMAKE_INIT_PRIVATE_HEADER_DIR})

###########################################
### sources from current dir
###########################################s
target_sources(tests PRIVATE main_test.cc cli_test.cc cmake_init_test.cc)

###########################################
### sources from subdirs
###########################################s
add_subdirectory(cmake_init)

include(GoogleTest)
gtest_discover_tests(tests)
