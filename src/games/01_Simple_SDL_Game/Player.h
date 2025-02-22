#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Player:public Entity{
public:
	~Player();

	void update();
	void draw(SDL_Renderer* renderer);
};

