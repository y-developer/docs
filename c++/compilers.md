# C / C++ compilers

## GCC (GNU Compiler Collection)
A widely used open-source compiler that supports C, C++, and other programming languages.

### C Codes
Compile using the gcc
```bash
gcc -o <executable_name> <source_file>.c
```

Run executable file
```bash
./<executable_name>
```

### C++ Codes
Compile using the g++
```bash
g++ -o <executable_name> <source_file>.cpp
```

Run executable file
```bash
./<executable_name>
```

## Clang
A C, C++, and Objective-C compiler developed by the LLVM(Low-Level Virtual Machine) Project. Known for its fast compile times and detailed error messages.

## Emscripten
An open-source compiler toolchain that allows you to compile C and C++ code into JavaScript and WebAssembly, which can then be run in a web browser or other JavaScript runtime environment.

**official website** :- https://emscripten.org/

### Install Emscripten
**Install on Linux systems**

Go to home directory
```bash
cd ~
```
Get the emsdk repo
```bash
git clone https://github.com/emscripten-core/emsdk.git .emscripten
```

Enter that directory
```bash
cd ./.emscripten
```

Download and install the latest SDK tools
```bash
./emsdk install latest
```

Make the "latest" SDK "active" for the current user. (writes .emscripten file)
```bash
./emsdk activate latest
```

Activate PATH and other environment variables in the terminal
```bash
echo 'source /home/<user_name>/.emscripten/emsdk_env.sh' >> ~/.bashrc
```

Open the new terminal and verify that the installation is correct.
```bash
emcc -v
```
### Compilling
#### Compile for Nodejs
`main.cpp` යන main function එක ඇති c++ file එක පහත පරිදි nodejs සදහා compile කරගත හැක.
```bash
emcc main.cpp
```
මෙහිදී `a.out.js` හා `a.out.wasm` යනුවෙන් files දෙකක් සෑදේ. මෙහි ඇති `a.out.js` යන file එක පහත පරිදි nodejs මගින් run කරගත හැක.
```bash
node a.out.js
```

#### Compile for Web
`main.cpp` යන main function එක ඇති c++ file එක පහත පරිදි html file එකක් ලෙස compile කරගත හැක.
```bash
emcc main.cpp -o hello.html
```
මෙහිදී `hello.html`, `hello.js` හා `hello.wasm` යනුවෙන් files තුනක් සෑදේ. මෙහි ඇති `hello.html` file එක web browser එකක් මගින් open කරගත හැක.
```bash
node a.out.js
```

## Microsoft Visual C++
A proprietary C++ compiler developed by Microsoft as part of Visual Studio, a popular integrated development environment (IDE) for Windows.

## Intel C++ Compiler
A proprietary compiler developed by Intel Corporation that is designed to optimize performance on Intel architecture.

## Borland C++
A commercial compiler that was popular in the 1990s, but has since been largely superseded by other compilers.

## Turbo C++
Another commercial compiler that was popular in the 1990s, but is no longer actively developed.

## Digital Mars C++
A proprietary compiler developed by Walter Bright that supports C++11 and C++14 standards.

## Embarcadero C++ Builder
A commercial compiler that includes an IDE for Windows development.

## Code::Blocks
An open-source, cross-platform IDE that supports multiple compilers, including GCC and Clang.

## Eclipse CDT
An open-source, cross-platform IDE that supports multiple compilers, including GCC and Clang.
