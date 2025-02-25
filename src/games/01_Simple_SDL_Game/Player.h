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
	void draw(SDL_Renderer* renderer);
	void set_movement(MOVE new_move);

protected:
	double x_pos = 0.5;
	double y_pos = 0.85;
	double width = 0.05;
	double height = 0.05;
	std::vector<double> color = {1.0, 1.0, 1.0, 1.0};

private:
	double step_size = 0.01;
	MOVE cur_movement = MOVE::NOTHING;
};

