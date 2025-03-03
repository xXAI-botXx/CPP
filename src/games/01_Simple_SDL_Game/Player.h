#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

class Player :public Entity {
public:
	Player();
	~Player();

	void update(double delta_time);
};


