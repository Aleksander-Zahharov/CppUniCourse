#ifndef POINT2_H
#define POINT2_H

#include <iostream>
using std::ostream;

class Point2 {

public:

	float x = 0;
	float y = 0;

	Point2() = default;
	Point2(float nx, float ny);
	float distanceFrom(Point2 v);
	
	friend ostream& operator << (ostream& valja, Point2 v); /*!< Kirjutab väljundvoogu punkti koordinaadid kujul (nx, ny).*/
};

#endif 
