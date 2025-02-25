
#include <vector>

#include "Math.h"


// Constructor
Vector2D::Vector2D(double x, double y) {
	values.push_back(x);
	values.push_back(y);
}

// Getter
double Vector2D::get_x(){
	return values.at(0);
}
double Vector2D::get_y(){
	return values.at(1);
}

// Scalarproduct
double Vector2D::dot(const Vector2D& other) const {
	return values[0] * other.values[0] + values[1] * other.values[1];
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




