#include <iostream>

std::int32_t user_input(){
    std::int32_t user_number = 0;
    std::cout << "Please enter a number: ";
    std::cin >> user_number;

    return user_number;
}

void print_bool(bool value) {
    std::cout << std::boolalpha << value;

    // return; -> is also possible to end the function
}

int main() {
    std::int32_t number_1 = user_input();
    std::int32_t number_2 = user_input();
    std::int32_t number_3 = user_input();

    bool my_bool = true;

    print_bool(my_bool);
    

    return 0;
}


