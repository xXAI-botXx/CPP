#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Wall:public Entity{
public:
	~Wall();

	void update();
	void draw(SDL_Renderer* renderer);
};

