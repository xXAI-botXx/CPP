#include <iostream>

unsigned int faculty(std::uint32_t i) {
    if (i == 1) {
        return 1;
    } else {
        return i * faculty(i-1);
    }
}

int main() {
    std::uint32_t user_input;
    std::cout << "Enter a number: ";
    std::cin >> user_input;

    std::cout << "Faculty of '" << user_input << "': " << faculty(user_input) << std::endl;

    return 0;
}


