######################
### REQUIRED
######################
cmake_minimum_required(VERSION 3.23)

project(
    glfw_glad_template
    VERSION "0.1.0.0" # major.minior.patch.tweak # 
    DESCRIPTION "Project description"
    HOMEPAGE_URL "www.Project.com"
    LANGUAGES "C" "CXX" # cxx -> c++
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

######################
### PROJECT VARIABLES
######################

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE) # for use in _config.hpp and other files
set(PROJECT_SRC_DIR ${PROJECT_SOURCE_DIR}/src) # src directory variable set
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include) # src directory variable set

######################
### CONFIG FILE
######################

configure_file( #pass settings to source code
    ${PROJECT_NAME}_config
    ${PROJECT_SOURCE_DIR}/src/config/${PROJECT_NAME}_config.hpp
)

######################
### SOURCE CODE DIRECTORY
######################

add_subdirectory(${PROJECT_SRC_DIR})
add_subdirectory(${PROJECT_INCLUDE_DIR})


######################
### CUSTOM TARGETS (needs fixing)
######################
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD  #used to generate a graph to see all dependencies
#                   COMMAND 
#                         ${CMAKE_COMMAND} --graphviz=foo.dot ${CMAKE_BINARY_DIR}
#                         dot -Tpng foo.dot -o foo.png # for svg chang -Tsvg and foo.svg
#                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#                   VERBATIM
# )