
#include<vector>
#include <SDL3/SDL.h>

#include "Math.h"
#include "Ball.h"

//Constructor
Ball::Ball() {
	x_pos = 0.4;
	y_pos = 0.4;
	width = 0.02;
	height = width;
	color = std::vector<double>{ 1.0, 1.0, 1.0, 1.0 };
	velocity = new Vector2D(0.01, 0.01);    // in heap
}

// Destructor
Ball::~Ball() {
	if (velocity) {
		delete velocity;
		velocity = nullptr;
	}
}

Ball::Ball(const Ball& other) : Entity(other) {
	velocity = new Vector2D(*other.velocity);
}

void Ball::update() {
	x_pos += velocity->get_x();
	y_pos += velocity->get_y();
}


bool Ball::is_on_bottom() {
	if (y_pos * window_height >= window_height - window_height * (width / 2)) {
		return true;
	}
	return false;
}


// reflectionvector bounce
void Ball::bounce(const Vector2D& normal) {
	Vector2D* n = new Vector2D(normal.normalize());    // in stack
	velocity = new Vector2D((*velocity) - (*n) * (2 * (*velocity).dot(*n)));
	delete n;
}









