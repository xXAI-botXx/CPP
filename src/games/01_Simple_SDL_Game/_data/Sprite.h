#pragma once

#include "Shape2D.h"

class Sprite:public Shape2D{
public:
	Sprite(double x, double y, double rotation, double scale, double width, double height,
			// bool have_animation, Animation2D animation,
			bool have_sprite, std::string sprite_path);
	~Sprite();

	SendDataResult send_data();
};



