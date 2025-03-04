
#include <vector>
#include <random>
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

	std::random_device rd;  // Hardware-Seed (if available)
	std::mt19937 gen(rd()); // Mersenne Twister PRNG
	std::uniform_real_distribution<double> dist(-0.25, 0.25);
	double x_speed = dist(gen);
	velocity = new Vector2D(x_speed, 0.25-x_speed);    // in heap
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

void Ball::update(double delta_time) {
	x_pos += velocity->get_x() * delta_time;
	y_pos += velocity->get_y() * delta_time;
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


Vector2D* Ball::get_velocity() {
	return this->velocity;
}









