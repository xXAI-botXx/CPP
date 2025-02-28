
#include <iostream>
#include<vector>
#include <SDL3/SDL.h>

#include "Player.h"

//Constructor
Player::Player() {
	cur_movement = MOVE::NOTHING;
	x_pos = 0.5;
	y_pos = 0.85;
	width = 0.05;
	height = 0.05;
	color = std::vector<double>{ 1.0, 1.0, 1.0, 1.0 };
}

// Destructor
Player::~Player() {

}

void Player::set_movement(MOVE new_move) {
	cur_movement = new_move;
}

void Player::update() {

	// new position
	double new_position_x = 0.0;
	double new_position_y = 0.0;

	switch (cur_movement) {
	case MOVE::NOTHING:
		break;
	case MOVE::LEFT:
		new_position_x = x_pos - step_size;
		break;
	case MOVE::RIGHT:
		new_position_x = x_pos + step_size;
		break;
	}

	// move
	if (new_position_x >= 0.0 && new_position_x + width <= 1.0 && false) {
		x_pos = new_position_x;
	}

	// print
	// std::cout << "x_pos: " << x_pos << ", y_pos: " << y_pos << ", width: " << width << ", height: " << height << std::endl;
	// std::cout << this->to_string() << std::endl;

}




