#include <algorithm>
#include <vector>
#include "Rectangle.h"
#include "Shape2D.h"

Rectangle::Rectangle(double x, double y, double rotation, double scale, double width, double height,
					bool has_fill_color, COLOR_REPRESENTATION fill_color_format, std::vector<double> fill_color,
					bool has_border_color, COLOR_REPRESENTATION border_color_format, std::vector<double> border_color){

	transform = Transform2D{x, y, rotation, scale, scale};
	bounding_box = BoundingBox{x-width/2, y-height/2, x+width/2, y+height/2};
	bounding_circle = BoundingCircle{x, y, std::max(width/2, height/2)};

	this->has_fill_color = has_fill_color;
	this->fill_color_format = fill_color_format;
	this->fill_color = fill_color;    // std::vector<double>

	this->has_border_color = has_border_color;
	this->border_color_format = border_color_format;
	this->border_color = border_color;    // std::vector<double>
}

Rectangle::~Rectangle(){

}

Rectangle::send_data(){

}







