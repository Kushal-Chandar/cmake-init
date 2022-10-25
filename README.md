# cmake-init

a cmake project with ci, code coverage, clang tidy, cpp check, graphviz, iwyu, gtest, etc.

dependency management -> msys2 and vcpkg

## Usage

Make sure you have base development packages for your environment.

You will need cmake, git, etc (some other requirements for vcpkg)

Open options.cmake to tweak some settings.

``` bash
mkdir build && cd build
cmake -S .. -B .
```

## Todo in CI

Static analysis -> markdownlint, clang-tidy, cppcheck, iwyu
Formatting ->  clang-format, cmake-format (todo add ci)
Sanitizer -> Clang sanitizers

todo -> testing, actions
testing ->  code coverage in github actions
actions -> github actions

## Goals

make an executable or a vscode extension to generate a project
