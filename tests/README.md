# Unit tests

One file per header file (both public and private) and the structure should be the same as src/impl/.

All files names are prefixed by _test

```bash
cmake-init
 ├── include
 │   └── cmake-init
 │       └── cmake_init_lib.h
 ├── src
 │   ├── configuration
 │   │   ├── config.h
 │   │   └── config.h.ini
 │   ├── inc
 │   │   └── cmake_init_lib
 │   │       └── print_greeting.h
 │   └── impl
 │       ├── cmake_init_lib
 │       │   └── print_greeting.h
 │       ├── cmake_init_lib.cc
 │       └── main.cpp
 ├── tests
 │   ├── cmake_init_lib
 │   │   └── print_greeting_test.h
 │   ├── cmake_init_lib_test.cc
 │   └── main_test.cpp
```