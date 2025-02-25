
#include "Entity.h"

#include <vector>
#include <cmath>
#include <SDL3/SDL.h>



// Destructor implementation
Entity::~Entity() {
	color.clear();
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

std::vector<double> get_pos_info(){
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
	SDL_FRect rect = {
		static_cast<int>(x_pos*window_width - (width/2)*window_width),
		static_cast<int>(y_pos*window_height - (height/2)*window_height),
		static_cast<int>(x_pos*window_width + (width/2)*window_width),
		static_cast<int>(y_pos*window_height + (height/2)*window_height)
	};
	const SDL_FRect* rect_p = &rect;

	// render
	SDL_RenderFillRect(renderer, rect_p);

	// reset
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	delete rect_p;
}


