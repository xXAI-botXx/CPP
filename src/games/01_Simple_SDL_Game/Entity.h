// = 0 makes the method abstract -> subclass have to overwrite it
// virtual keyword makes it possible to inherit the method
#pragma once

#include <vector>
#include <queue>
#include <string>
#include <SDL3/SDL.h>

#include "GraphicsData.h"


enum MOVE2D {
	LEFT,
	RIGHT,
	NOTHING
};


class Entity {
public:
	Entity() = default;
	Entity(const Entity& other);
	// virtual Entity; -> not possible
	virtual ~Entity();

	std::string to_string();

	//Getter
	double get_abs_x_left_corner();
	double get_abs_y_left_corner();
	double get_abs_x_center();
	double get_abs_y_center();
	double get_rel_x_center();
	double get_rel_y_center();
	double get_abs_width();
	double get_abs_height();
	double get_rel_width();
	double get_rel_height();
	std::vector<GraphicsData*> get_graphic_data();

	virtual void update(double delta_time) = 0;

	std::vector<int> color_scaling();
	void update_window_size(int window_width, int window_height);
	bool collide_with_other(const Entity* other_entity);
	std::vector<double> get_pos_info() const;
	void add_movement(MOVE2D new_move);

protected:    // is accessible in subclasses
	double x_pos{};    // brace initialization -> init with 0
	double y_pos{};
	double width{};
	double height{};

	std::vector<double> color = { 1.0, 1.0, 1.0, 1.0 };
	const int color_max = 255;

	int window_width{};
	int window_height{};

	double step_size = 0.85;
	std::queue<MOVE2D> movement_queue;
};




