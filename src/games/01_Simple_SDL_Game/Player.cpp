
#include<vector>
#include <SDL3/SDL.h>

#include "Player.h"

//Constructor
Player::Player() {
	cur_movement = MOVE::NOTHING;
}

// Destructor
Player::~Player() {

}

void set_movement(MOVE new_move) {
	cur_movement = new_move;
}

void Player::update(){

	// new position
	double new_position_x;
	double new_position_y;

	switch(cur_movement) {
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
	if(new_position_x >= 0.0 && new_position_x+width <= 1.0){
		x_pos = new_position_x;
	}

}




