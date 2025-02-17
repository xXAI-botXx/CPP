#include <iostream>
#include <cstdint>

/**
 * Disclaimer:
 * This is the C-Style Array.
 * The C-Style Array should be not be used.
 * It is just a pointer to the start of the array, but without the size, it is unknown where it ends.
 * So when you use it as parameter, you always also have to give the size with it.
 * Most mistakes in C/C++ Code comes from a wrong memory access with these C-Style arrays
 * and with pointers which points to memory which not longer belongs to the program.
 * 
 * C++ Style:
 * - std::array -> constant array
 * - std::string -> dynamic char array
 * - std::vector -> dynamic array
 * 
 * (not in this file)
 */

int main(){
    
    std::int32_t arr_1[5] = {23, 4, -1, 34, 4};

    std::cout << arr_1[0] << std::endl;
    std::cout << arr_1[3] << std::endl;
    std::cout << arr_1[11] << std::endl;    // Dangerous, looks in another space!

    /**
     * arr_1[0] == *(arr_1 + 0)
     * 
     * so it just will increments the pointer to the given amount and give the value of the incremented pointer 
     * you need the () because it should first increase the amount and then give the value of this memory address
     * -> see pointer.cpp and heap_c_style.cpp
     */

    int arr_2[2];
    arr_2[0] = 0;
    // ...

    // you can also init an array with a a given length and then it will take the amount of given objects as max length
    int arry_3[] = {2, 4, 6, 7};



    // Example:
    constexpr auto len = std::uint32_t{3U};
    // constecpr std::uint32_t = 3;

    float vector_1[len]{};  // this is a good practise to make sure every value is 0 and not a (random) number from memory
    float vector_2[len];
    
    for (int i=0; i < len; ++i) {
        std::cout << vector_1[i] << ", " << vector_2[i] << std::endl;
    }

    std::cout << "\nLet's define Vector 1:\n";
    for (int i=0; i < len; ++i) {
        std::cout << "Give me a number: ";
        std::cin >> vector_1[i];
    }

    std::cout << "\nLet's define Vector 2:\n";
    for (int i=0; i < len; ++i) {
        std::cout << "Give me a number: ";
        std::cin >> vector_2[i];
    }

    std::cout << "\nResult:\n";
    for (int i=0; i < len; ++i) {
        std::cout << vector_1[i] << ", " << vector_2[i] << std::endl;
    }

    return 0;
}



