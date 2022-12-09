# What should be put in ${PROJECT_NAME} directory in include?

Public Headers.
Public headerfiles contain the interface of your library to be used by others (and yourself),
if you have internal header files put them in src/inc.

In case of header only libraries the entire code is going to be in this folder.

## Things to Note

- You will be able to access the header file like this "header1.h", in this case "cmake_init_lib.h"

- The users of library will access files in the following fashion &lt;${PROJECT_NAME}/header1.h&gt;,
in this case, &lt;cmake-init/cmake_init_lib.h&gt;
