### INCLUDE

###################### 
### MUST ONLY CONTAIN PUBLIC HEADERS (mainly used for building library)
######################

### for applications just add this folder to .gitignore unless
### there is library which is others could use (make this public)

add_library(
    array_utils STATIC
    array_utils/print_array.hpp
    ${PROJECT_SRC_DIR}/array_utils/print_array.cpp
)
target_include_directories(array_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})