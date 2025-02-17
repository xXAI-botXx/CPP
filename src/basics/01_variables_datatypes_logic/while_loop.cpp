#include <iostream>

// break; -> stops a loop
// continue; -> starts the next loop

int main(){
    
    std::uint32_t sum = 0;
    std::uint32_t goal_sum = 42; 

    while (sum < goal_sum) {
        std::cout << sum << " is smaller than " << goal_sum << "\nYou add: ";
        std::uint32_t user_input;
        std::cin >> user_input;
        sum += user_input;
    }

    // do-while: a while-loop which always runs once

    do {
        std::cout << sum << " is smaller than " << goal_sum << "\nYou add: ";
        std::uint32_t user_input;
        std::cin >> user_input;
        sum += user_input;
    } while (sum < goal_sum);

    return 0;
}



