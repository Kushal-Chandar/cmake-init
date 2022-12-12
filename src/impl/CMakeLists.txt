#####################################################
### Source files in IMPL
#####################################################

# add source files available in this directory to any target your want

target_sources(lib PRIVATE cmake_init.cc)
target_sources(cli PRIVATE cli.cc)
target_sources(app PRIVATE main.cc)

#####################################################
### Source files in other subdirectories
#####################################################
add_subdirectory(cmake_init)
