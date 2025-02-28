
#include <vector>
#include <cmath>

// for precise double to str
#include <sstream>
#include <iomanip>
#include <string>

#include "Math.h"



std::string double_to_string(const double& value, int precision) {
	std::ostringstream out;
	out << std::fixed << std::setprecision(precision) << value;
	return out.str();
	// return std::to_string(value).substr(0, std::to_string(value).find('.') + precision + 1);
}



// #################
// ### Vektor 2D ###
// #################
// Constructor
Vector2D::Vector2D(double x, double y) {
	values.push_back(x);
	values.push_back(y);
}
Vector2D::Vector2D(const Vector2D& other_vector) {
	values.push_back(other_vector.get_x());
	values.push_back(other_vector.get_y());
}

// Getter
double Vector2D::get_x() const {
	return values.at(0);
}
double Vector2D::get_y() const {
	return values.at(1);
}

// Scalarproduct
double Vector2D::dot(const Vector2D& other) const {
	return values[0] * other.get_x() + values[1] * other.get_y();
}

// Substraction
Vector2D Vector2D::operator-(const Vector2D& other) const {
	return Vector2D(values[0] - other.values[0], values[1] - other.values[1]);
}

// Multiplication with scalar
Vector2D Vector2D::operator*(double scalar) const {
	return Vector2D(values[0] * scalar, values[1] * scalar);
}

// Normalization (length 1)
Vector2D Vector2D::normalize() const {
	float length = std::sqrt(values[0] * values[0] + values[1] * values[1]);
	return Vector2D(values[0] / length, values[1] / length);
}




