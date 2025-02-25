
#include<vector>
#include <SDL3/SDL.h>

#include "Ball.h"

//Constructor
Ball::Ball() {
	velocity = Vector2D(0.01, 0.01);    // in stack
}

// Destructor
Ball::~Ball() {
	delete velocity;
}

void Ball::update(){
	x_pos += velocity.get_x();
	y_pos += velocity.get_y();
}


bool Ball::is_on_bottom(){
	if(y_pos*window_height >= window_height-window_height*(width/2)){
		return true;
	}
	return false;
}


// reflectionvector bounce
void bounce(Vector2D normal){
	Vector2D n = normal.normalize();    // in stack
	velocity = velocity - n * (2 * velocity.dot(n));
}









