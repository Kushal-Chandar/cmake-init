# What should be put in ${PROJECT_NAME} directory in include?

Public Headers.
Public headerfiles contain the interface of your library to be used by others (and yourself),
if you have internal header files put them in src/inc.

In case of header only libraries the entire code is going to be in this folder.

The users of library will access files in the following fashion &lt;${PROJECT_NAME}/header1.h&gt;
In this case, &lt;cmake-init/cmake_init_lib.h&gt;
