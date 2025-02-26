#pragma once

#include <SDL3/SDL.h>
#include "Entity.h"
#include "Math.h"


class Ball:public Entity{
public:
	Ball();
	~Ball();

	void update();
	bool is_on_bottom();
	void bounce(const Vector2D& normal);

private:
	Vector2D* velocity;
};
