#include "../include/circle2.h"
#include <cmath> // For M_PI

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Default constructor
Circle2::Circle2() : p1(Point2()), r(0) {}

// Parameterized constructor
Circle2::Circle2(Point2 np1, float nr) : p1(np1), r(nr < 0 ? 0 : nr) {}	// Checks if the radius is negative, if it is, it sets it to 0

// Method to calculate the circumference (length of the circle)
float Circle2::circumference() const {
    return 2 * M_PI * r;
}

// Method to calculate the area
float Circle2::area() const {
    return M_PI * r * r;
}

// Method to check if a point is inside the circle
bool Circle2::contains(Point2 p) const {
    return p1.distanceFrom(p) <= r;	// If the distance between the center of the circle and the point is less than or equal to the radius, then the point is inside the circle
}

// Method to check if a line is inside the circle
bool Circle2::contains(Line2 l) const {
    return contains(l.p1) && contains(l.p2);	// If both vertices(points) are inside the circle, then the line is inside the circle as well
}

// Method to scale the radius with error handling
void Circle2::scale(float factor) {
	if (factor < 0) {
		throw std::invalid_argument("Scale factor must be positive number.");
	}
	r *= factor;
}

// Output operator. Outputs the circle in the form "(p1, r)"
ostream& operator<<(ostream& os, const Circle2& circle) {
    os << "(" << circle.p1 << ", " << circle.r << ")";
    return os;
}