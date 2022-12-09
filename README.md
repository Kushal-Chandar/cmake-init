# cmake-init

a cmake project with ci, code coverage, clang tidy, cpp check, graphviz, iwyu, gtest, etc.

dependency management -> msys2 and vcpkg

## Features

- Automatic versioning with git annotated tags,
  _please follow [semantic versioning](https://semver.org/) for accurate and predictable results._
- Custom project variables

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
