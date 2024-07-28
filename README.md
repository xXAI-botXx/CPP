<h1><a name="top">C++</a></h1>

This project contains the basics of C++ language.

May use it as a reference.


<h4 style="text-align:center"><a href="#topic_">Topics</a><h4>
<h4 style="text-align:center"><a href="#installation_">Installation</a><h4>
<h4 style="text-align:center"><a href="#runcppcode">Run C++ Code</a><h4>



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
- ...



Games:
- [Guessing Game](./games/guessing_game/)
- [Game 1](./games/computer_game_1/)
- ...



Projects:
- ...



---
<h3><a href="#top" name="installation_">Installation</a><h3>

- Download a C++ Compiler in **Windows**:
    - https://cygwin.com/install.html
    - Testing: 
    ```terminal
    make --version
    gdb --version
    gcc --version
    g++ --version
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
<h3><a href="#top" name="runcppcode">Run C++ Code</a><h3>

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

