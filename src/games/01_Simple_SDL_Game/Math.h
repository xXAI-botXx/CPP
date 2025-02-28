#pragma once

#include <vector>
#include <string>


std::string double_to_string(const double& value, int precision = 6);

class Vector2D {
public:
	// Constructor
	Vector2D(double x, double y);
	Vector2D(const Vector2D& other_vector);

	// Getter
	double get_x() const;
	double get_y() const;

	// Scalarproduct
	double dot(const Vector2D& other) const;    // const makes sure that the method can't change a value inside of the method

	// Substraction
	Vector2D operator-(const Vector2D& other) const;

	// Multiplication with scalar
	Vector2D operator*(double scalar) const;

	// Normalization (length 1)
	Vector2D normalize() const;

private:
	std::vector<double> values;
};

















