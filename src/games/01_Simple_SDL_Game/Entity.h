// = 0 makes the method abstract -> subclass have to overwrite it
// virtual keyword makes it possible to inherit the method
#pragma once

#include <vector>
#include <SDL3/SDL.h>

class Entity{
public:
	Entity() = default;
	// virtual Entity; -> not possible
	virtual ~Entity;

	virtual void update() = 0;
	virtual void draw(SDL_Renderer* renderer) = 0;

	std::vector<int> color_scaling();

protected:    // is accessible in subclasses
	double x_pos{};    // brace initialization -> init with 0
	double y_pos{};
	double width{};
	double height{};
	std::vector<double> color = {1.0, 1.0, 1.0, 1.0};
	constexpr int color_max = 255;
};



