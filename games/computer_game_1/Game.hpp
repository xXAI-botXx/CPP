#pragma once

#include <iostream>
#include <cstdint>

// constexpr std::uint32_t LEN_X = 10U;
// constexpr std::uint32_t START = 0U;
// constexpr std::uint32_t GOAL = 9U;
// constexpr char LEFT = 'a';
// constexpr char RIGHT = 'd';

void print_field(const std::uint32_t player_position);
bool is_finish(const std::uint32_t player_position);
void execute_move(std::uint32_t& player_position, const char move);
void play_game();

