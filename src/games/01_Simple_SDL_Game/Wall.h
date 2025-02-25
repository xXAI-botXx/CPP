#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Wall:public Entity{
public:
	Wall(int x_pos, int y_pos);
	~Wall();

	void update();
	void draw(SDL_Renderer* renderer);

protected:
	double width = 0.04;
	double height = 0.02;
	std::vector<double> color = {0.1, 1.0, 0.2, 1.0};
};



