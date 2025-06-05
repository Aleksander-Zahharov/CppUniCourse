#include "Point2.h"
#include <cmath>

using namespace std;


Point2::Point2(float nx, float ny)
	: x {nx}
  	, y {ny}
{
}


float Point2::distanceFrom(Point2 v) {
    return sqrt( (x - v.x)*(x - v.x) + (y - v.y)*(y - v.y) ); 
}

ostream& operator << (ostream& os, Point2 v) {
	return os << "(" << v.x << "," << v.y << ")";
}
