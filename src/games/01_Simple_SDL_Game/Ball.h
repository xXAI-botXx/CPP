#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Ball:public Entity{
public:
	~Ball();

	void update();
	void draw(SDL_Renderer* renderer);
};

