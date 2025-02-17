#include <iostream>

// link to the interface of this file
#include "Game.hpp"

// variables only available in this file -> use namespace
namespace{
    constexpr std::uint32_t LEN_X = 10U;
    constexpr std::uint32_t START = 0U;
    constexpr std::uint32_t GOAL = 9U;
    constexpr char LEFT = 'a';
    constexpr char RIGHT = 'd';
};

void print_field(const std::uint32_t player_position){
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


bool is_finish(const std::uint32_t player_position) {
    return player_position == GOAL;
}


void execute_move(std::uint32_t& player_position, const char move){
    if (move == RIGHT) {
            std::cout << "Moving to RIGHT" << std::endl;
            player_position += 1;
        } else if (move == LEFT && player_position > 0) {
            std::cout << "Moving to LEFT" << std::endl;
            if (player_position > 0)
                player_position -= 1;   
        } else {
            std::cout << "'" << move << "' is not a move. Try again..." << std::endl;
        }
}


void play_game(){
    std::uint32_t player_position = START;
    char user_input;

    print_field(player_position);

    while (not is_finish(player_position)) {
        /*
        if (player_position == GOAL) {
            break;
        }
        */

        std::cout << "User: ";
        std::cin >> user_input;

        execute_move(player_position, user_input);

        print_field(player_position);
    }
}


