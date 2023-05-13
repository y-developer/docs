# C++ Build Systems

## CMake
CMake is a cross-platform build system that generates native build files for a wide range of platforms and compilers. It uses CMakeLists.txt files to define the build configuration and supports a variety of build options and generators.

### Install cmake
Install on Debian, Ubuntu and derivatives
```bash
sudo apt install cmake
```
Check cmake version
```bash
cmake --version
```

## Meson
Meson is a modern build system that aims to be fast, easy to use, and cross-platform. It supports a wide range of programming languages, including C++, and uses meson.build files to define the build configuration.

**official website** :- https://mesonbuild.com/ <br>
**youtube tutorial** :- https://www.youtube.com/watch?v=LDMNWYLpklc

### Install meson
How to install:- https://mesonbuild.com/SimpleStart.html <br>
Releases:- https://github.com/mesonbuild/meson/releases

Install on Debian, Ubuntu and derivatives
```bash
sudo apt install meson ninja-build
```
Check meson and ninja version
```bash
meson --version
```
```bash
ninja --version
```

## Make
Make is a classic build system that is widely used for building C++ libraries. It uses Makefile files to define the build configuration and supports a variety of build options and targets.
Install on Debian, Ubuntu and derivatives

### Install make
```bash
sudo apt install build-essential
```
*build-essential has dpkg-dev, g++, gcc, libc6-dev, make*

Check make version
```bash
make --version
```

## Autotools
Autotools is a collection of tools used to build and distribute C++ libraries on Unix-like systems. It includes tools such as autoconf, automake, and libtool, which are used to generate configure scripts and Makefile.in files.

## Ninja
Ninja is a fast and lightweight build system that is designed to be more efficient than traditional build systems like Make. It uses a simple build.ninja file to define the build configuration and supports parallel builds.

### Install ninja
```bash
sudo apt install ninja-build
```
Check ninja version
```bash
ninja --version
```
## Bazel
Bazel is a build system developed by Google that is designed to be highly scalable and support large, complex projects. It uses a BUILD file to define the build configuration and supports a variety of programming languages, including C++.

**official website** :- https://bazel.build/ <br>
**youtube tutorial** :- https://www.youtube.com/watch?v=kLLDzLWzuag

### Install bazel


## SCons
SCons is a Python-based build system that uses a SConstruct file to define the build configuration. It supports a variety of build options and targets and is designed to be highly flexible and customizable.

### Install scons
Install on Debian, Ubuntu and derivatives
```bash
sudo apt install scons
```
Check scons version
```bash
scons --version
```
