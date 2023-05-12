# C++ Build Systems

## CMake
CMake is a cross-platform build system that generates native build files for a wide range of platforms and compilers. It uses CMakeLists.txt files to define the build configuration and supports a variety of build options and generators.

## Meson
Meson is a modern build system that aims to be fast, easy to use, and cross-platform. It supports a wide range of programming languages, including C++, and uses meson.build files to define the build configuration.

**official website** :- https://mesonbuild.com/

### Check meson install or not
```bash
meson --version
```
```bash
ninja --version
```
### Install meson
How to install:- https://mesonbuild.com/SimpleStart.html
Releases:- https://github.com/mesonbuild/meson/releases

Install on Debian, Ubuntu and derivatives
```bash
sudo apt install meson ninja-build
```

## Make
Make is a classic build system that is widely used for building C++ libraries. It uses Makefile files to define the build configuration and supports a variety of build options and targets.

## Autotools
Autotools is a collection of tools used to build and distribute C++ libraries on Unix-like systems. It includes tools such as autoconf, automake, and libtool, which are used to generate configure scripts and Makefile.in files.

## Ninja
Ninja is a fast and lightweight build system that is designed to be more efficient than traditional build systems like Make. It uses a simple build.ninja file to define the build configuration and supports parallel builds.

## Bazel
Bazel is a build system developed by Google that is designed to be highly scalable and support large, complex projects. It uses a BUILD file to define the build configuration and supports a variety of programming languages, including C++.

## SCons
SCons is a Python-based build system that uses a SConstruct file to define the build configuration. It supports a variety of build options and targets and is designed to be highly flexible and customizable.
