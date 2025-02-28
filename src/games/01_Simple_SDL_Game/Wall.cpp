
#include<vector>
#include <SDL3/SDL.h>

#include "Wall.h"

//Constructor
Wall::Wall(int x_pos, int y_pos, double width, double height) {
	this->x_pos = x_pos;
	this->y_pos = y_pos;
	this->width = width;
	this->height = height;
	color = std::vector<double>{ 0.1, 0.5, 0.1, 1.0 };
}

// Destructor
Wall::~Wall() {

}

void Wall::update() {

}






