#####################################################
### Source files in INC
#####################################################

# add source files available in this directory to any target your want
target_sources(lib PRIVATE) # can be removed just added for completeness
target_sources(app PRIVATE) # can be removed just added for completeness
target_sources(cli PRIVATE cli.h)

#####################################################
### Source files in other subdirectories
#####################################################
add_subdirectory(cmake_init)
