#include <iostream>

// Will copy the variable
void func_1(int i){
    ++i;
    std::cout << &i << std::endl;
    std::cout << i << std::endl;
}

// Will create a new pointer but on the same variable
// pointer need more memory then a reference
void func_2(int* i){
    ++*i;
    std::cout << i << std::endl;
    std::cout << *i << std::endl;
}

// There is just the same variable as before (careful -> sideeffects)
// It will create a pointer with 64bit or 32bit and you can handle it 
// as same as the real variable, so it only in the back a pointer, you have the real variable
// By using constant variables (like as input parameter) it is always to consider if using a reference or an copy
// a reference is first beneficial when the datatype is >= 64 bit/ 8 Byte or 32 bit / 4 Byte
void func_3(int& i){
    ++i;
    std::cout << &i << std::endl;
    std::cout << i << std::endl;
}

// if a func has output it should be a copy (depends on the specific scenario)
// if you want to change the value of an parameter in a function without an output than you should use a reference or an pointer

int main(){
    std::cout << "Init i:" << std::endl;
    int i = 0;
    std::cout << &i << std::endl;
    std::cout << "    -> init i is:" << i << std::endl;

    std::cout << "\nIfunc 1 - i:" << std::endl;
    func_1(i);
    std::cout << "    -> init i is:" << i << std::endl;

    // will probably get the same memory address as before but
    // it is a complete new variable. The other func is finish and the memory get released and used now by this new call.
    std::cout << "\nIfunc 1 (second run) - i:" << std::endl;
    func_1(i);
    std::cout << "    -> init i is:" << i << std::endl;

    std::cout << "\nIfunc 2 - i:" << std::endl;
    func_2(&i);
    std::cout << "    -> init i is:" << i << std::endl;

    std::cout << "\nIfunc 3 - i:" << std::endl;
    func_3(i);
    std::cout << "    -> init i is:" << i << std::endl;

    return 0;
}


/**
 * Result:

Init i:
0x7ffffcc0c
    -> init i is:0

Ifunc 1 - i:
0x7ffffcbe0
1
    -> init i is:0

Ifunc 1 (second run) - i:
0x7ffffcbe0
1
    -> init i is:0

Ifunc 2 - i:
0x7ffffcc0c
1
    -> init i is:1

Ifunc 3 - i:
0x7ffffcc0c
2
    -> init i is:2
    
 */


