#pragma once

#include "Entity.h"
#include <SDL3/SDL.h>

enum MOVE{
	LEFT,
	RIGHT,
	NOTHING
};

class Player:public Entity{
public:
	Player();
	~Player();

	void update();
	void set_movement(MOVE new_move);


private:
	double step_size = 0.01;
	MOVE cur_movement = MOVE::NOTHING;
};

