
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <SDL3/SDL.h>

#include "Math.h"

#include "Entity.h"



// Destructor implementation
Entity::~Entity() {
	color.clear();
}

// Getter
double Entity::get_abs_x_left_corner(){
	return (x_pos - width*0.5)*window_width;
}

double Entity::get_abs_y_left_corner(){
	return (y_pos - height*0.5)*window_height;
}

double Entity::get_abs_x_center(){
	return x_pos*window_width;
}

double Entity::get_abs_y_center(){
	return y_pos*window_height;
}

double Entity::get_rel_x_center(){
	return x_pos;
}

double Entity::get_rel_y_center(){
	return y_pos;
}

int Entity::get_abs_width(){
	return width*window_width;
}

int Entity::get_abs_height(){
	return height*window_height;
}

int Entity::get_rel_width(){
	return width;
}

int Entity::get_rel_height(){
	return height;
}


std::string Entity::to_string(){
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

void Entity::update_window_size(int window_width, int window_height){
	this->window_width = window_width;
	this->window_height = window_height;
}

bool Entity::collide_with_other(const Entity* other_entity){
	// get position information from other entity
	std::vector<double> pos_info = other_entity->get_pos_info();
	double other_x_pos = pos_info.at(0);
	double other_y_pos = pos_info.at(1);
	double other_width = pos_info.at(2);
	double other_height = pos_info.at(3);

	// check fast with circle distant and then with SAT
	if(abs(x_pos-other_x_pos)+abs(y_pos-other_y_pos) <= (width/2+other_width/2 + height/2+other_height/2)){
		// calc now with SAT
		// ... FIXME
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


void Entity::draw(SDL_Renderer* renderer){
	// set color
	std::vector<int> rgb_color = this->color_scaling();
	SDL_SetRenderDrawColor(renderer, rgb_color.at(0), rgb_color.at(1), rgb_color.at(2), 255);

	// set position
	SDL_FRect rect = SDL_FRect{
		static_cast<float>(get_abs_x_left_corner()),
		static_cast<float>(get_abs_y_left_corner()),
		// static_cast<float>(x_pos*window_width + (width*0.5)*window_width),
		// static_cast<float>(y_pos*window_height + (height*0.5)*window_height)
		static_cast<float>(get_abs_width()),
		static_cast<float>(get_abs_height())
	};

	// const SDL_FRect* rect_p = &rect;

	// render
	SDL_RenderFillRect(renderer, &rect);

	// reset
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
}


