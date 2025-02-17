#include <iostream>

/**
 * Static only runs in compile time and during run time it doesn't will run.
 * It will be saved in another place.
 */

// global variable
constexpr float MULTIPLY_FACTOR = 2.0;

float multiply(const float input_value) {
    static int counter = 0;

    ++counter;
    std::cout << "Counter: " << counter << "\n";

    return input_value * MULTIPLY_FACTOR;
}

int main(){
    constexpr float i = 0.5 * 3.78 / 34;
    std::cout << multiply(i) << std::endl;
    std::cout << multiply(i) << std::endl;
    std::cout << multiply(i) << std::endl;
    std::cout << multiply(i) << std::endl;

    return 0;
}


