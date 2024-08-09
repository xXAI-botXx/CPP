<h1><a name="top">C++</a></h1>

This project contains the basics of C++ language.

May use it as a reference.


<h4 style="text-align:center"><a href="#topic_">Topics</a><h4>
<h4 style="text-align:center"><a href="#installation_">Installation of GNU Compiler Collection</a><h4>
<h4 style="text-align:center"><a href="#installation_clang">Installation of Clang</a><h4>
<h4 style="text-align:center"><a href="#runcppcode">Run C++ Code with GNU</a><h4>
<h4 style="text-align:center"><a href="#runcppcode_with_clang">Run C++ Code with Clang</a><h4>



<img src="./cover.jpeg"></img>






---
<h3><a href="#top" name="topic_">Topics</a><h3>

- [Hello World](./00_hello_world/main.cpp)
- Variables, Datatypes and Logic
  - [Variables](./01_variables_datatypes_logic/variables.cpp)
  - [Data Types](./01_variables_datatypes_logic/datatypes.cpp)
  - [User Input](./01_variables_datatypes_logic/user_input.cpp)
  - [If Else](./01_variables_datatypes_logic/if_else.cpp)
  - [Ternary](./01_variables_datatypes_logic/ternary_operator.cpp)
  - [For Loops](./01_variables_datatypes_logic/for_loop.cpp)
  - [While Loops](./01_variables_datatypes_logic/while_loop.cpp)
  - [Functions](./01_variables_datatypes_logic/functions.cpp)
  - [Recursion](./01_variables_datatypes_logic/recursion.cpp)
  - [Overloaded Funtions](./01_variables_datatypes_logic/function_overloading.cpp)
  - [Templates](./01_variables_datatypes_logic/template.cpp)
  - [Pre and Post Increment](./01_variables_datatypes_logic/post_and_pre_increment.cpp)
  - [Constant Variables](./01_variables_datatypes_logic/const.cpp)
  - [Static Local Variables](./01_variables_datatypes_logic/static_local_var.cpp)
  - [Casting](./01_variables_datatypes_logic/casting.cpp)
  - [Auto Keyword](./01_variables_datatypes_logic/auto_keyword.cpp)
- Arrays
  - [Arrays](./02_pointer_and_arrays/arrays.cpp)
  - [Strings](./02_pointer_and_arrays/string.cpp)
  - [Multidimensionale Arrays](./02_pointer_and_arrays/multidimensional_arrays.cpp)
  - [Arrays in C++ Style](./02_pointer_and_arrays/arrays_cpp_style.cpp)
  - [Pointer](./02_pointer_and_arrays/pointer.cpp)
  - [Heap in C Style](./02_pointer_and_arrays/heap_c_style.cpp)
  - [Nullpointers](./02_pointer_and_arrays/nullpointers.cpp)
  - [Pointer Arrays](./02_pointer_and_arrays/pointer_arrays.cpp)
  - [References](./02_pointer_and_arrays/references.cpp)
  - [Argc and Argv](./02_pointer_and_arrays/argc_argv.cpp)
- ...



Games:
- [Guessing Game](./games/guessing_game/)
- [Game 1](./games/computer_game_1/)
- ...



Projects:
- ...



---
<h3><a href="#top" name="installation_">Installation of GNU Compiler Collection</a><h3>

You can decide whether to install GNU Compiler Collection (GCC) or Clang. Both are great and both are covered in this README. I would recommend Clang, but that is personal preference.

- Download a C++ Compiler in **Windows**:
    - https://cygwin.com/install.html
    - make sure to install following extension (use the search bar，choose a version and click that it should get download):
        - gcc-g++
        - gcc-core
        - make
        - gdb
    - Add cygwin to the system path variables. Then you can use the normal cmd or Powershell or the terminal in Visual Studio Code.<br>To do so，you have to search/open the system-variables (environment variables). There you search the entry "Path", there should be already some paths. To these paths you add the path of Cygwin bin folder, probably: **C:\cygwin64\bin** <br>And now it should work. Maybe a restart is requirement, if it doesn't works.
    - Testing: 
    ```terminal
    make --version
    gdb --version
    gcc --version
    g++ --versiono
    ```



- Download a C++ Compiler in **Linux**:
    - Installation: 
    ```terminal
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install make
    sudo apt-get install gdb
    sudo apt-get install gcc
    sudo apt-get install g++
    sudo apt-get install git
    sudo apt-get install cmake
    ```
    - Testing: 
    ```terminal
    gdb --version
    gcc --version
    g++ --version
    ```



---
<h3><a href="#top" name="installation_clang">Installation (Clang/LLVM)</a><h3>

You can also download Clang, it is an alternative compiler for C and C++:

1. Go to the [official Webiste](https://clang.llvm.org/)
2. Click on [download](https://releases.llvm.org/download.html)
3. Go to the [release page](https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8) of the newest release
4. For windows click on the LLVM-18.1.8-win64.exe
5. In windows you can then execute the exe file 

In Linux do following:
```terminal
sudo apt update && sudo apt upgrade
sudo apt install clang
clang --version
sudo apt install llvm
```


Testing: 
```terminal
clang --version
```

<!--and in linux you can decompress it with "tar -xvf mycompressed.tar.xz". Then you can follow the instructions in the README or if not available, then run:
    ```terminal
    ./configure
    make
    sudo make install
    ```
-->


<a href="#runcppcode_with_clang">Here are more informations to Clang, what it is and how to use it.</a>



---
<h3><a href="#top" name="runcppcode">Run C++ Code (with g++)</a><h3>

The GNU Compiler Collection (GCC) is a standard compiler for c and c++ and here you see how to use it.



Most simple way to compile a C++ program with Clang is to create a **make** file and use make to compile your C++-Files (for this you can install cygwin in Windows to use make <a href="#installation_">see here</a>):
```terminal
# Compiler
CXX = g++  # Use this if you're using MinGW or Cygwin

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# List of source files
SRCS = main.cpp file1.cpp file2.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Name of the output executable
TARGET = my_program.exe

# Default target: build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

```

The Makefile is just a plain textfile without a file type ending. Just name the file "Makefile" and execute it with "make".



Another way is to type following in a terminal:
1. First you compile your program and create a executeable file:
    - ```terminal
      g++ main.cpp -o main
      ```
    - If you have multiple C++ Files you can do:
    ```terminal
    g++ -o main main.cpp game.cpp
    ```
    or:
    ```terminal
    g++ -c main.cpp
    g++ -c game.cpp
    g++ -o main main.o game.o
    ```
2. Then you can execute it:
    ```terminal
    ./main.exe
    ```
    Or in Linux:
    ```terminal
    ./main
    ```



> Hint:<br>Use the terminal and navigate with cd .. and cd 01_variables_datatypes_logic to the right folder.<br>You also can type 00 and then tab-key to use auto completion.



In Depth:
- assemble:
```terminal
g++ -S program.cpp
```
- compile:
```terminal
g++ -c program.cpp -o program.o
```
- build:
```terminal
g++ program.o -o program
```


> You can add a parameter at the beginning of every command to specify how much the code should be optimized. For debugging it is common to not optimize your code to can analyze your code.<br>For Debugging: g++ -O0 -g3 ...<br>For Release: g++ -O3 ...



---
<h3><a href="#top" name="runcppcode_with_clang">Run C++ Code (with clang++)</a><h3>

Clang is a compiler front end for the C, C++, and Objective-C programming languages. It is part of the LLVM (Low-Level Virtual Machine) project and provides tools for compiling code, checking syntax, and generating executable files. Clang is known for its fast compilation times, detailed error messages, and modular design.<br>
Clang is a powerful and versatile compiler that is widely used in the development of system software, games, and many other applications. Its fast compilation times, excellent diagnostic tools, and extensibility make it a valuable tool for developers. Whether you're writing code, debugging, or optimizing, Clang provides a comprehensive suite of features to support your workflow.


**Key Features**

- **Fast Compilation**: Clang is optimized for speed, making it suitable for large codebases.
- **Detailed Diagnostics**: It provides clear and concise error and warning messages, helping developers quickly identify and fix issues.
- **Modular Design**: Clang is designed to be easily extendable and configurable, making it a popular choice for building custom tooling.
- **Cross-Platform**: Clang is available on multiple platforms, including Linux, macOS, and Windows.



**Compiling a Program**

Most simple way to compile a C++ program with Clang is to create a **make** file and use make to compile your C++-Files (for this you can install cygwin in Windows to use make <a href="#installation_">see here</a>):
```terminal
# Compiler
CXX = clang++
# CXX = g++  # Use this if you're using MinGW or Cygwin

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# List of source files
SRCS = main.cpp file1.cpp file2.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Name of the output executable
TARGET = my_program.exe

# Default target: build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

```

The Makefile is just a plain textfile without a file type ending. Just name the file "Makefile" and execute it with "make".



Alternativly you can use the following commands:

```terminal
clang++ -o output_file source_file.cpp
```
This command generates an executable named `output_file` from `source_file.cpp`.

Or for multiple files:
```terminal
clang++ -o my_project main.cpp file1.cpp file2.cpp
```



Here is a indepth view of the compilation:
1. Compile your source code to an object file
    ```terminal
    clang++ -c main.cpp -o main.o
    clang++ -c file1.cpp -o file1.o
    clang++ -c file2.cpp -o file2.o
    ```
    And with external library/include a directory:
    ```terminal
    clang++ -I/path/to/include -c file1.cpp -o file1.o
    ```
2. Now you can link them together to an executable file
    ```terminal
    clang++ main.o file1.o file2.o -o my_project
    ```
    And with external library:
    ```terminal
    clang++ main.o file1.o file2.o -L/path/to/libs -lmylib -o my_project
    ```



> On Windows you hve probably install Visual Studio to make Clang work.



**Enabling Warnings**

Clang provides various warning options to help catch potential issues in your code. For example, to enable all warnings, you can use the `-Wall` flag:

```bash
clang -Wall -o output_file source_file.c
```



**Debugging**

To generate debugging information, use the `-g` flag:

```bash
clang -g -o output_file source_file.c
```

This flag makes it easier to debug the program using tools like `gdb` or `lldb`.



**Optimization**

For optimized builds, use the `-O` flag followed by the optimization level (0, 1, 2, 3, or `fast`):

```bash
clang -O2 -o output_file source_file.c
```

Higher optimization levels can improve performance but may increase compilation time and executable size.



**Clang Tools**

Clang also includes several useful tools:

- **Clang Format**: A tool to format C, C++, and Objective-C code.
- **Clang Static Analyzer**: A tool for static code analysis to find bugs.
- **Clang Tidy**: A tool for linting and automatic code transformations.


For more detailed information and advanced features, refer to the [official Clang documentation](https://clang.llvm.org/docs/).



---

