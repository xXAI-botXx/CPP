# C++

This project contains the basics of C++ language.

May use it as a reference.



---
### Installation

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
### Ausführung

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



---
### Contents

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
  - [Overloded Funtions](./01_variables_datatypes_logic/function_overloading.cpp)
  - [Templates](./01_variables_datatypes_logic/template.cpp)
- ...



Games:
- [Guessing Game](./games/guessing_game/main.cpp)
- [Game 1](./games/computer_game_1.cpp)
- ...



Projects:
- ...





