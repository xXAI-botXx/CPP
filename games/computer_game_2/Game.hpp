#pragma once

#include <cstdint>

struct Coordinate {
   std::uint32_t x;
   std::uint32_t y;
};

enum class ConsoleInput {
   INVALID,
   LEFT,
   RIGHT,
   UP,
   DOWN
};


// constexpr std::uint32_t LEN_X = 10U;
// constexpr std::uint32_t START = 0U;
// constexpr std::uint32_t GOAL = 9U;
// constexpr char LEFT = 'a';
// constexpr char RIGHT = 'd';

void print_field(const Coordinate& player_position);
bool is_finish(const Coordinate& player_position);
void execute_move(Coordinate& player_position, const char move);
void play_game();

