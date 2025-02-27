#pragma once

#include "Shape2D.h"

class Rectangle:public Shape2D{
public:
	Rectangle(double x, double y, double rotation, double scale, double width, double height,
				bool has_fill_color, COLOR_REPRESENTATION fill_color_format, std::vector<double> fill_color,
				bool has_border_color, COLOR_REPRESENTATION border_color_format, std::vector<double> border_color);
	~Rectangle();

	SendDataResult send_data();
};
