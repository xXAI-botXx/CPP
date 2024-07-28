#include <iostream>

template <typename T>
void print_pointer(T* my_awesome_pointer) {
    if (my_awesome_pointer != nullptr) {
        std::cout << "Your pointer points to " << my_awesome_pointer;
        std::cout << " with the value -> " << *my_awesome_pointer << std::endl;
    } else {
        std::cout << "Your pointer points to nothing (" << my_awesome_pointer << ")\n";
    }
}

int main(){
    std::int32_t* my_awesome_number = new std::int32_t{34};
    delete my_awesome_number;
    my_awesome_number = nullptr;
    print_pointer(my_awesome_number);


    auto* my_other_awesome_number = new float{12.52};
    print_pointer(my_other_awesome_number);

    return 0;
}

/*
Result:

Your pointer points to nothing (0)
Your pointer points to 0xa00001db0 with the value -> 12.52
*/

