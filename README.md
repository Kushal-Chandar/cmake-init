# cmake-init

[![c++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B)](https://en.cppreference.com/w/)
[![cmake](https://img.shields.io/badge/CMake-1b8b40.svg?logo=cmake&logoColor=white)](https://cmake.org/)

a cmake project with ci, code coverage, clang tidy, cpp check, graphviz, iwyu, gtest, etc.

dependency management -> vcpkg

## Features

- Automatic versioning with git annotated tags,
  _please follow [semantic versioning](https://semver.org/) for accurate and predictable results._
- Custom project variables.

```cmake
# -----------------------------------------------------------------------------------
#   Setting custom variables
# if your project name is cmake-init
# CMAKE_INIT_PUBLIC_HEADER_DIR variable -> public headers (include/${PROJECT_NAME})
# CMAKE_INIT_PRIVATE_HEADER_DIR variable -> private headers (src/inc)
# CMAKE_INIT_SOURCE_DIR variable -> source files (src)
# CMAKE_INIT_IMPL_DIR variable -> implementation (src/impl)
# CMAKE_INIT_TEST_DIR variable -> implementation (test)
# -----------------------------------------------------------------------------------
```

- Easy to use project structure.

```bash
cmake-init
 ├── include
 │   └── cmake-init
 │       └── cmake_init.h
 ├── src
 │   ├── config
 │   │   ├── config.h
 │   │   └── config.h.ini
 │   ├── inc
 │   │   ├── cmake_init
 │   │   │   ├── print_greeting.h
 │   │   │   └── CMakeLists.txt
 │   │   ├── cli.h
 │   │   └── CMakeLists.txt
 │   └── impl
 │       ├── cmake_init
 │       │   ├── print_greeting.h
 │       │   └── CMakeLists.txt
 │       ├── cmake_init.cc
 │       ├── cli.cc
 │       ├── main.cc
 │       └── CMakeLists.txt
 ├── tests
 │   ├── cmake_init
 │   │   ├── print_greeting_test.h
 │   │   └── CMakeLists.txt
 │   ├── cmake_init_test.cc
 │   ├── cli_test.cc
 │   ├── main_test.cc
 │   └── CMakeLists.txt
 └── CMakeLists.txt
```

- CMakeLists.txt file in every directory lets you sources easily to your target without any prefixing
(Please read the comments in CMakeLists.txt files for a better understanding).

## Usage

Make sure you have base development packages for your environment.

You will need cmake, git, etc (some other requirements for vcpkg)

Open options.cmake to tweak some settings.

``` bash
mkdir build && cd build
cmake -S .. -B .
```

## NOTE

This template uses MIT License. Please feel free to change this to your intended license before publishing the software.

## Todo in CI

Static analysis -> markdownlint, clang-tidy, cppcheck, iwyu
Formatting ->  clang-format, cmake-format (todo add ci)
Sanitizer -> Clang sanitizers

todo -> testing, actions
testing ->  code coverage in github actions
actions -> github actions

## Goals

make an executable or a vscode extension to generate a project
