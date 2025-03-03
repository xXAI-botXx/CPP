
#include <iostream>
#include<vector>
#include <SDL3/SDL.h>

#include "Entity.h"
#include "Player.h"

//Constructor
Player::Player() {
	x_pos = 0.5;
	y_pos = 0.85;
	width = 0.085;
	height = 0.05;
	color = std::vector<double>{ 1.0, 1.0, 1.0, 1.0 };
}

// Destructor
Player::~Player() {

}

void Player::update(double delta_time) {

	MOVE2D last_move = MOVE2D::NOTHING;

	while(!movement_queue.empty()){
		MOVE2D cur_movement = movement_queue.front();
		movement_queue.pop();

		if (last_move != cur_movement) {
			last_move = cur_movement;

			// new position
			double new_position_x = 0.0;
			double new_position_y = 0.0;

			switch (cur_movement) {
			case MOVE2D::NOTHING:
				break;
			case MOVE2D::LEFT:
				new_position_x = x_pos - step_size;    // * delta_time
				break;
			case MOVE2D::RIGHT:
				new_position_x = x_pos + step_size;    // * delta_time
				break;
			}

			// move
			if (new_position_x + (width * 0.5) >= 1.0 && cur_movement != MOVE2D::NOTHING) {
				x_pos = 1.0; // - (width * 0.5)
			}
			else if (new_position_x - (width * 0.5) <= 0.0 && cur_movement != MOVE2D::NOTHING) {
				x_pos = 0.0 + width; // + (width * 0.5)
			}
			else if (cur_movement != MOVE2D::NOTHING) {
				x_pos = new_position_x;
			}

			// print
			// std::cout << "x_pos: " << x_pos << ", y_pos: " << y_pos << ", width: " << width << ", height: " << height << std::endl;
			// std::cout << this->to_string() << std::endl;
		}
	}
}




