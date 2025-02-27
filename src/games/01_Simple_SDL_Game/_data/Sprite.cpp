#include <algorithm>
#include <vector>
#include "Sprite.h"
#include "Shape2D.h"

Sprite::Sprite(double x, double y, double rotation, double scale, double width, double height,
				// bool have_animation, Animation2D animation,
				bool have_sprite, std::string sprite_path){

	transform = Transform2D{x, y, rotation, scale, scale};
	bounding_box = BoundingBox{x-width/2, y-height/2, x+width/2, y+height/2};
	bounding_circle = BoundingCircle{x, y, std::max(width/2, height/2)};

//	this->have_animation = have_animation;
//	this->animation = animation;

	this->have_sprite = have_sprite;
	this->sprite_path = sprite_path;
}


Sprite::~Sprite(){

}


