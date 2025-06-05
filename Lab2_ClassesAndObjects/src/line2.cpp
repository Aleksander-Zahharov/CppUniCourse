#include "../include/line2.h"

// Default constructor creates points using Point2 default constructor
Line2::Line2() {
	p1 = Point2();
	p2 = Point2();
}

// Parameterized constructor initializes points with given values
Line2::Line2(Point2 np1, Point2 np2) 
	: p1(np1), p2(np2) {}

// Method to calculate the length of the line
float Line2::length() const {
    return p1.distanceFrom(p2);
}

// Output operator to print line data in the form (p1 - p2)
ostream& operator<<(ostream& os, const Line2& line) {
    os << "(" << line.p1 << " - " << line.p2 << ")";
    return os;
}