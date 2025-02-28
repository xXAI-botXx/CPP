#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Wall :public Entity {
public:
	Wall(double x_pos, double y_pos, double width, double height);
	~Wall();

	void update();

};




