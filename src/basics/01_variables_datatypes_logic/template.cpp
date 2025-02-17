#include <iostream>

// Also called: Generic

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    double number_double_1 = 2.7;
    double number_double_2 = 3.14;
    std::cout << max(number_double_1, number_double_2) << std::endl;
    std::cout << max<double>(number_double_1, number_double_2) << std::endl;

    uint32_t number_uint32_1 = 34;
    uint32_t number_uint32_2 = 3;
    std::cout << max(number_uint32_1, number_uint32_2) << std::endl;

    return 0;
}



