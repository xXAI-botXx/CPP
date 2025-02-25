#pragma once

#include <SDL3/SDL.h>
#include "Entity.h"
#include "Math.h"


class Ball:public Entity{
public:
	Ball();
	~Ball();

	void update();
	void draw(SDL_Renderer* renderer);
	bool is_on_bottom();
	void bounce(Vector2D normal);

protected:
	double x_pos = 0.4;
	double y_pos = 0.4;
	Vector2D* velocity;
	double width = 0.02;
	double height = 0.02;
	std::vector<double> color = {1.0, 1.0, 1.0, 1.0};
};
