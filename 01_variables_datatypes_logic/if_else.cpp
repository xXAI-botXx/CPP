#include <iostream>

/*
Greater Equal: >=
Greater: >
Equal: ==
Less: <
Less Equal: <=

And: &&
Or: ||
*/

int main(){

    std::uint32_t secret_number = 345665;

    std::uint32_t guess;
    std::cout << "Please enter your guess (number): ";
    std::cin >> guess;

    /*
    bool check = (guess >= 0 && guess <= 4'200'000'000)
    std::cout << "Check: " << std::boolalpha << check << std::endl;
    */

    if (guess >= 0 && guess <= 4'200'000'000) {   // or 42e8
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

    return 0;
}

