#include <iostream>

int main() {
    std::uint32_t LEN_X = 10U;
    std::uint32_t START = 0U;
    std::uint32_t GOAL = 9U;

    char LEFT = 'a';
    char RIGHT = 'd';

    std::uint32_t player_position = START;

    char user_input;

    while (player_position != GOAL) {
        /*
        if (player_position == GOAL) {
            break;
        }
        */
        std::cin >> user_input;

        if (user_input == RIGHT) {
            std::cout << "Moving to RIGHT" << std::endl;
            player_position += 1;
        } else if (user_input == LEFT && player_position > 0) {
            std::cout << "Moving to LEFT" << std::endl;
            if (player_position > 0)
                player_position -= 1;   
        } else {
            std::cout << "'" << user_input << "' is not a move. Try again..." << std::endl;
        }

        for (std::uint16_t i = 0; i < 10; i++) {
            if (i == player_position) {
                std::cout << "P";
            } else if (i == GOAL) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

