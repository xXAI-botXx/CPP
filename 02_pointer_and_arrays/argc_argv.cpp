#include <iostream>
#include <cstdlib>

// you can pass arguments when you call your executive file
// just split the arguments with an whitespace

// argc: argument count
// argv: argument values
int main(int argc, char** argv){
    // char** tells that an 2D array will be given
    // char** is a pointer to an pointer
    // and a 2D Array is exactly that, a pointer which points to another pointer
    // when increasing the pointer (argv)[1] then the next element will be again a pointer and points to the next value
    // so we have a pointer who points to other pointer = 2D char array


    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    if (argc > 1) {
        int my_arg_int = std::atoi(argv[1]);
    }

    return 0;
}


