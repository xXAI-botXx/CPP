#include <iostream>

/**
 * Pointers point to a memory address and thus consume little memory, but they can still indirectly 
 * hold and modify values. The actual value of the variable being pointed to is changed in reality.
 * 
 * For example, in function calls, a new variable does not always have to be created for each parameter.
 * 
 * Pointers are indicated by an * after the data type, and &variable gives us the memory address of a variable.
 * 
 * Following formats are correct:
 *      1. int* my_pointer
 *      2. int * my_pointer
 *      3. int *my_pointer
 * 
 * You can use a pointer like:
 *      - my_pointer -> this will return the memory adress where the pointer points to
 *      - &my_pointer -> this will just give the memory address of the pointer itself
 *      - *my_pointer -> this will return the value of the variable where the pointer points to
 * 
 *  &: Reference
 *  *p: De-reference
 */

// ! these functions can't be used:
// !    -> the functions manipulates the result, because it will create new pointers
// void print_variable(int int_to_print, bool add_pre_space) {
//     if (add_pre_space)
//         std::cout << "\n";
//     std::cout << "Variable Value: " << int_to_print << ", Memory Adress: " << &int_to_print << "\n";
// }

// void print_variable(int* int_to_print, bool add_pre_space) {
//     if (add_pre_space)
//         std::cout << "\n";
//     std::cout << "Pointer Value: " << *int_to_print << ", Memory Adress: " << int_to_print << ", Points to: " << &int_to_print << "\n";
// }

int main(){
    std::cout << "\n";

    int num = 42;
    // print_variable(num, false);
    std::cout << "Variable Value: " << num << ", Memory Adress: " << &num << "\n";

    int* num_p = &num;
    //print_variable(num_p, false);
    std::cout << "Pointer Value: " << *num_p << ", Memory Adress: " << &num_p << ", Points to: " << num_p << "\n";
    std::cout << std::addressof(num_p) << std::endl;
    int* num_p_2 = &num;
    // print_variable(num_p_2, false);
    std::cout << "Pointer Value: " << *num_p_2 << ", Memory Adress: " << &num_p_2 << ", Points to: " << num_p_2 << "\n";


    // now we increment the variable and the pointer
    std::cout << "\n";
    ++num;
    // print_variable(num, true);
    std::cout << "Variable Value: " << num << ", Memory Adress: " << &num << "\n";
    // print_variable(num_p, false);
    std::cout << "Pointer Value: " << *num_p << ", Memory Adress: " << &num_p << ", Points to: " << num_p << "\n";

    std::cout << "\n";
    ++*num_p;
    // print_variable(num, true);
    std::cout << "Variable Value: " << num << ", Memory Adress: " << &num << "\n";
    // print_variable(num_p, false);
    std::cout << "Pointer Value: " << *num_p << ", Memory Adress: " << &num_p << ", Points to: " << num_p << "\n";

    return 0;
}

/**
 * Possible Output:

Variable Value: 42, Memory Adress: 0x7ffffcbfc
Pointer Value: 42, Memory Adress: 0x7ffffcbf0, Points to: 0x7ffffcbfc
0x7ffffcbf0
Pointer Value: 42, Memory Adress: 0x7ffffcbe8, Points to: 0x7ffffcbfc

Variable Value: 43, Memory Adress: 0x7ffffcbfc
Pointer Value: 43, Memory Adress: 0x7ffffcbf0, Points to: 0x7ffffcbfc

Variable Value: 44, Memory Adress: 0x7ffffcbfc
Pointer Value: 44, Memory Adress: 0x7ffffcbf0, Points to: 0x7ffffcbfc

 */

