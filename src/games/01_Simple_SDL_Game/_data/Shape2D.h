#pragma once

#include <vector>
#include <string>
#include <map>
#include "GraphicsData.h"

struct Transform2D{
    double x = 0.0;  // Center Position X
    double y = 0.0;  // Center Position Y
    double rotation = 0.0; // Rotation in Grad
    double scale_x = 1.0; // Scale X
    double scale_y = 1.0; // Scale Y
};

struct BoundingBox{
    double min_x = 0.0;
    double min_y = 0.0;
    double max_x = 0.0;
    double max_y = 0.0;
};

struct BoundingCircle{
    double center_x = 0.0;
    double center_y = 0.0;
    double radius = 0.0;
};

// animation have to checked, how to implement
//struct Animation2D{
//	// Transform2D rel_transformations;
//	std::vector<std::string> paths;
//	std::vector<double> times;
//};

class Shape2D:public GraphicsData{
public:
	virtual ~Shape2D() = default;

	// virtual SendDataResult send_data() = 0;
protected:
	Transform2D transform;
	BoundingBox bounding_box;
	BoundingCircle bounding_circle;

//	bool have_animation = false;
//	Animation2D animation;

	bool have_sprite = false;
	std::string sprite_path;

	// if animation and sprite -> first animation, then show sprite

	bool has_fill_color = false;
	COLOR_REPRESENTATION fill_color_format = COLOR_REPRESENTATION::RGBA;
	std::vector<double> fill_color;

	bool has_border_color = false;
	COLOR_REPRESENTATION border_color_format = COLOR_REPRESENTATION::RGBA;
	std::vector<double> border_color;
};










