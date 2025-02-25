#pragma once

#include <vector>


class Vector2D{
public:
	// Constructor
	Vector2D(double x, double y);

	// Getter
	double get_x();
	double get_y();

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
















