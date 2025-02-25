// = 0 makes the method abstract -> subclass have to overwrite it
// virtual keyword makes it possible to inherit the method
#pragma once

#include <vector>
#include <SDL3/SDL.h>

class Entity{
public:
	Entity() = default;
	// virtual Entity; -> not possible
	virtual ~Entity();

	virtual void update() = 0;
	virtual void draw(SDL_Renderer* renderer);

	std::vector<int> color_scaling();
	void update_window_size(int window_width, int window_height);
	bool collide_with_other(const Entity* other_entity);
	std::vector<double> get_pos_info();

protected:    // is accessible in subclasses
	double x_pos{};    // brace initialization -> init with 0
	double y_pos{};
	double width{};
	double height{};

	std::vector<double> color = {1.0, 1.0, 1.0, 1.0};
	const int color_max = 255;

	int window_width{};
	int window_height{};
};



