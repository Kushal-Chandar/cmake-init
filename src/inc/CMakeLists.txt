#####################################################
### Source files in INC
#####################################################

# add source files available in this directory to any target your want
target_sources(cmake-init_lib PRIVATE
)# can be removed just added for completeness

target_sources(cmake-init_app PRIVATE
)# can be removed just added for completeness

target_sources(cmake-init_cli PRIVATE cli.h)

#####################################################
### Source files in other subdirectories
#####################################################
add_subdirectory(cmake_init_lib)
