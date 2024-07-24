#include <iostream>

// FIXME

double max(double a, double b) {
    return a > b ? a : b;
}

unsigned int max(std::uint32_t a, std::uint32_t b) {
    return a > b ? a : b;
}

int main() {
    double number_double_1 = 2.7;
    double number_double_2 = 3.14;
    std::cout << max(number_double_1, number_double_2) << std::endl;

    uint32_t number_uint32_1 = 34;
    uint32_t number_uint32_2 = 3;
    std::cout << max(number_uint32_1, number_uint32_2) << std::endl;

    return 0;
}



