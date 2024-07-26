#include <iostream>

#include "Game.hpp"

void print_field(std::uint32_t player_position){
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

void play_game(){
    std::uint32_t player_position = START;
    char user_input;

    print_field(player_position);

    while (player_position != GOAL) {
        /*
        if (player_position == GOAL) {
            break;
        }
        */

        std::cout << "User: ";
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

        print_field(player_position);
    }
}


