#include <iostream>

// link to the interface of this file
#include "Game.hpp"

// variables only available in this file -> use namespace
namespace{
    constexpr std::uint32_t LEN_X = 10U;
    constexpr std::uint32_t LEN_Y = 5U;
    constexpr Coordinate START = Coordinate{.x=0, .y=0};
    constexpr Coordinate GOAL = Coordinate{.x=LEN_X-1, .y=LEN_Y-1};
    constexpr char LEFT = 'a';
    constexpr char RIGHT = 'd';
    constexpr char UP = 'w';
    constexpr char DOWN = 's';
};

ConsoleInput cinput_to_enum(const char move, const Coordinate player_position) {
    if (move == RIGHT && player_position.x < LEN_X-1) {
        return ConsoleInput::RIGHT;
    } else if (move == LEFT && player_position.x > 0) {
        return ConsoleInput::LEFT;
    } else if (move == UP && player_position.y > 0) {
        return ConsoleInput::UP;  
    } else if (move == DOWN && player_position.y < LEN_Y-1) {
        return ConsoleInput::DOWN;
    } else {
        return ConsoleInput::INVALID;
    }
}

void print_field(const Coordinate& player_position){
    for (std::uint16_t y_pos = 0; y_pos < LEN_Y; y_pos++) {
        for (std::uint16_t x_pos = 0; x_pos < LEN_X; x_pos++) {
            if (x_pos == player_position.x and y_pos == player_position.y) {
                std::cout << "P";
            } else if (x_pos == GOAL.x and y_pos == GOAL.y) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


bool is_finish(const Coordinate& player_position) {
    return player_position.x == GOAL.x and player_position.y == GOAL.y;
}


void execute_move(Coordinate& player_position, const ConsoleInput move, const char original_input){
    switch(move) {
        case (ConsoleInput::RIGHT): {
            std::cout << "Moving to RIGHT" << std::endl;
            player_position.x += 1;
            break;
        } case (ConsoleInput::LEFT): {
            std::cout << "Moving to LEFT" << std::endl;
            player_position.x -= 1;   
            break;
        } case (ConsoleInput::UP): {
            std::cout << "Moving to UP" << std::endl;
            player_position.y -= 1; 
            break; 
        } case (ConsoleInput::DOWN): {
            std::cout << "Moving to DOWN" << std::endl;
            player_position.y += 1;
            break;
        } case(ConsoleInput::INVALID): {
            std::cout << "'" << original_input << "' is not a move. Try again..." << std::endl;
            break;
        } default: {
            std::cout << "Invalid input. Try again..." << std::endl;
            break;
        }
    }
}


void play_game(){
    Coordinate player_position = START;
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

        ConsoleInput move_mapped = cinput_to_enum(user_input, player_position);
        execute_move(player_position, move_mapped, user_input);

        print_field(player_position);
    }

    std::cout << "YEAHHHH You Won!" << std::endl;
}


