###################### 
### CONTAINS SOURCE FILES AND PRIVATE HEADERS
######################


###################### 
### SOURCE FILES
######################
set(SRC_FILES
    ${PROJECT_SRC_DIR}/main.cpp
)

###################### 
### EXECUTABLE
######################
add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
)

###################### 
### PRIVATE HEADERS
######################
add_library(
    configuration STATIC
    ${PROJECT_SRC_DIR}/config/glfw_glad_template_config.hpp
    ${PROJECT_SRC_DIR}/config/glfw_glad_template_config.cpp
)
target_include_directories(configuration INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

###################### 
### LINKER FOR EXECUTABLE
######################
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    array_utils
    configuration
)
