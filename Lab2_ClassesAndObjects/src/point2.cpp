#include "../include/point2.h"
#include <cmath> // For sqrt function
#include <iostream> // For ostream

using namespace std;

// Default constructor initializes coordinates to zero
Point2::Point2() : x(0), y(0) {}

// Parameterized constructor initializes coordinates with given values
Point2::Point2(float nx, float ny) : x(nx), y(ny) {}

// Method to calculate distance from another point
float Point2::distanceFrom(Point2 p) const{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

// Overloaded output operator to print point coordinates in the form "(x, y)"
ostream& operator<<(ostream& os, const Point2& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}