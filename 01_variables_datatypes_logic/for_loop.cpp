#include <iostream>

int main() {

    for (std::uint32_t i=0; i<3; i+=1) {
        std::cout << i << std::endl;
    }

    unsigned int number;
    std::cout << "Give a number to check if it is a prime number: ";
    std::cin >> number;

    bool is_prime = true;

    if (number == 0 || number == 1) {
        is_prime = false;
    }

    for (unsigned int i = 2; i < number; i++) {
        if (number % i == 0) {
            is_prime = false;
            // break; -> stops a loop
            // continue; -> starts the next loop
        }
    }

    if (is_prime) {
        std::cout << "Your number is a prime number!" << std::endl;
    } else {
        std::cout << "Your number is NOT a prime number!" << std::endl;
    }
    

    return 0;
}


