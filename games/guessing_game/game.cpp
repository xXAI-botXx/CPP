#include <iostream>

#include "game.hpp"

void game(){

    std::uint32_t secret_number = 345665;

    std::uint32_t guess;

    while (guess != secret_number) {
        std::cout << "Please enter your guess (number): ";
        std::cin >> guess;


        if (guess >= 0 && guess <= 4'200'000'000) {   
            if (guess == secret_number) {
                std::cout << "Wow you are awesome, you are right!" << std::endl;
            } else if (guess > secret_number) {
                std::cout << "Your number is too high!" << std::endl;
            } else {
                std::cout << "Your number is too low!" << std::endl;
            }

            // modulo calculation => rest of division
            if (guess % 2 == 0) {
                std::cout << "Super, your guess is even!" << std::endl;
            }
        } else {
            std::cout << "The number have to be between 0 and 4.200.000.000" << std::endl;
        }
    }
}




