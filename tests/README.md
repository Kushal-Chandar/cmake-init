# Unit tests

One file per header file (both public and private) and the structure should be the same as src/impl/.

All files names are prefixed by _test

```bash
cmake-init
 ├── include
 │   └── cmake-init
 │       └── cmake_init_lib.h
 ├── src
 │   ├── config
 │   │   ├── config.h
 │   │   └── config.h.ini
 │   ├── inc
 │   │   ├── cli.h
 │   │   └── cmake_init_lib
 │   │       └── print_greeting.h
 │   └── impl
 │       ├── cmake_init_lib.cc
 │       ├── cli.cc
 │       ├── cmake_init_lib
 │       │   └── print_greeting.h
 │       └── main.cc
 ├── tests
 │   ├── cmake_init_lib_test.cc
 │   ├── cli_test.cc
 │   ├── cmake_init_lib
 │   │   └── print_greeting_test.h
 │   └── main_test.cc
```
