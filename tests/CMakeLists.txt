###########################################
### Required packages
###########################################
find_package(GTest CONFIG REQUIRED)

###########################################
### cmake-init tests
###########################################
add_executable(cmake-init_tests main.cc cmake_init_lib.cc
                                cmake_init_lib/print_greeting.cc)
target_link_libraries(cmake-init_tests PRIVATE GTest::gtest_main
                                               coverage_options)
target_link_libraries(cmake-init_tests PRIVATE cmake_init_lib)
# add you libs (can propagate target to sub dir?)
include(GoogleTest)
gtest_discover_tests(cmake-init_tests)
