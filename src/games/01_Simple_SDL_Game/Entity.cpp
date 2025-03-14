
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <SDL3/SDL.h>

#include "Math.h"
#include "GraphicsData.h"
#include "Rectangle.h"
#include "Ball.h"

#include "Entity.h"



Entity::Entity(const Entity& other) {
	x_pos = other.x_pos;    // brace initialization -> init with 0
	y_pos = other.y_pos;
	width = other.width;
	height = other.height;

	color = other.color;
	// color_max = other.color_max;

	window_width = other.window_width;
	window_height = other.window_height;

	step_size = other.step_size;
	movement_queue = other.movement_queue;
}

// Destructor implementation
Entity::~Entity() {
	color.clear();
}

// Getter
double Entity::get_abs_x_left_corner() {
	return (x_pos - (width * 0.5)) * window_width;
}

double Entity::get_abs_y_left_corner() {
	return (y_pos - (height * 0.5)) * window_height;
}

double Entity::get_abs_x_center() {
	return x_pos * window_width;
}

double Entity::get_abs_y_center() {
	return y_pos * window_height;
}

double Entity::get_rel_x_center() {
	return x_pos;
}

double Entity::get_rel_y_center() {
	return y_pos;
}

double Entity::get_abs_width() {
	return width * window_width;
}

double Entity::get_abs_height() {
	return height * window_height;
}

double Entity::get_rel_width() {
	return width;
}

double Entity::get_rel_height() {
	return height;
}


std::string Entity::to_string() {
	std::string entity_str = "\nEntity:";
	entity_str += "\n    - rel x: " + double_to_string(get_rel_x_center(), 4);
	entity_str += "\n    - rel y: " + double_to_string(get_rel_y_center(), 4);
	entity_str += "\n    - rel width: " + double_to_string(get_rel_width(), 4);
	entity_str += "\n    - rel height: " + double_to_string(get_rel_height(), 4);
	entity_str += "\n    - abs x: " + std::to_string(get_abs_x_center());
	entity_str += "\n    - abs y: " + std::to_string(get_abs_y_center());
	entity_str += "\n    - abs x (left): " + std::to_string(get_abs_x_left_corner());
	entity_str += "\n    - abs y (left): " + std::to_string(get_abs_y_left_corner());
	entity_str += "\n    - abs width: " + std::to_string(get_abs_width());
	entity_str += "\n    - abs height: " + std::to_string(get_abs_height());
	return entity_str;
}


// Implement color_scaling() outside the class
std::vector<int> Entity::color_scaling() {
	std::vector<int> color_scaled;
	for (double cur_element : color) {
		color_scaled.push_back(static_cast<int>(cur_element * color_max));
	}
	return color_scaled;
}

void Entity::update_window_size(int window_width, int window_height) {
	this->window_width = window_width;
	this->window_height = window_height;
}

bool Entity::collide_with_other(const Entity* other_entity) {
	// get position information from other entity
	std::vector<double> pos_info = other_entity->get_pos_info();
	double other_x_pos = pos_info.at(0);
	double other_y_pos = pos_info.at(1);
	double other_width = pos_info.at(2);
	double other_height = pos_info.at(3);

	double other_radius = std::max(other_width / 2, other_height / 2);
	double radius = std::max(width / 2, height / 2);

	// check fast with circle distant and then with SAT
	if (abs(x_pos - other_x_pos) + abs(y_pos - other_y_pos) <= (width / 2 + other_width / 2 + height / 2 + other_height / 2)) {
		// calc now with SAT
		// ... FIXME

		// only if velocity is towards the object
		if (Ball* ball = dynamic_cast<Ball*>(this)) {
			if (this->y_pos >= other_y_pos && ball->get_velocity()->get_y() >= 0.0) {
				return false;
			}
			else if (this->y_pos < other_y_pos && ball->get_velocity()->get_y() < 0.0) {
				return false;
			}
		}
		return true;
	}
	return false;
}

std::vector<double> Entity::get_pos_info() const {
	std::vector<double> pos_info;
	pos_info.push_back(x_pos);
	pos_info.push_back(y_pos);
	pos_info.push_back(width);
	pos_info.push_back(height);
	return pos_info;
}


std::vector<GraphicsData*> Entity::get_graphic_data() {
	std::vector<GraphicsData*> all_graphics_data;

	std::vector<int> rgb_color = this->color_scaling();

	GraphicsData* graphics_data = new Rectangle(
		get_abs_x_left_corner(),
		get_abs_y_left_corner(),
		0.0,
		1.0,
		get_abs_width(),
		get_abs_height(),
		true,
		COLOR_REPRESENTATION::RGBA,
		rgb_color,
		false,
		COLOR_REPRESENTATION::RGBA,
		std::vector<int>{}
	);

	all_graphics_data.push_back(graphics_data);
	return all_graphics_data;
}



void Entity::add_movement(MOVE2D new_move) {
	movement_queue.push(new_move);
}






