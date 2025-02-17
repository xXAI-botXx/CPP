#include <iostream>

// auto will lead to that the compile decide which datatype the variable is
// This is helpful, when it is obvious which datatype will be 
// and when it is not important which datatype is set

int main(){
    auto int_1 = 1;

    auto float_1 = static_cast<float>(int_1);

    auto double_1 = static_cast<double>(float_1);

    return 0;
}


