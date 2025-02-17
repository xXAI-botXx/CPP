#include <iostream>

// the keyword const makes a variable unchangable
// constexpr is the same but it also will be calculated during compilation
//    -> so constexpr can only be used when the value is fix duing compilation

// global variable
constexpr float MULTIPLY_FACTOR = 2.0;

float multiply(const float input_value) {
    
    return input_value * MULTIPLY_FACTOR;
}

int main(){
    constexpr float i = 0.5 * 3.78 / 34;
    std::cout << multiply(i) << std::endl;

    return 0;
}


