#####################################################
### Source files in IMPL
#####################################################

# add source files available in this directory to any target your want

target_sources(cmake-init_lib PRIVATE cmake_init_lib.cc)
target_sources(cmake-init_cli PRIVATE cli.cc)
target_sources(cmake-init_app PRIVATE main.cc)

#####################################################
### Source files in other subdirectories
#####################################################
add_subdirectory(cmake_init_lib)
