#include <iostream>

void print_func(int i) {
    std::cout << i << std::endl;
}

int main(){
    int a = 0;          // lvalue
    const int b = 1;    // constant lvalue
    int& c = a;         // lvalue reference
    const int& d = b;   // const lvalue reference

    print_func(a);
    print_func(b);
    print_func(c);
    print_func(d);
    print_func(42);     // rvalue

    return 0;
}






