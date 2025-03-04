#pragma once

#include <SDL3/SDL.h>
#include "Entity.h"
#include "Math.h"


class Ball :public Entity {
public:
	Ball();
	Ball(const Ball& other);
	~Ball();

	void update(double delta_time);
	bool is_on_bottom();
	void bounce(const Vector2D& normal);

	Vector2D* get_velocity();

private:
	Vector2D* velocity;
};

