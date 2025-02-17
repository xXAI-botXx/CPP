#include <iostream>

// Casting C++ Style:
// static_cast<new_data_type>(var_name);

int main(){
    int int_1 = 1;

    float float_1 = static_cast<float>(int_1);

    double double_1 = static_cast<double>(float_1);

    return 0;
}



