#ifndef LINE2_H
#define LINE2_H

#include "point2.h"
#include <iostream>
using std::ostream;

/**
 * @class Line2
 * @brief Represents a line segment in 2D space.
 */
class Line2 {
public:
    Point2 p1; ///< First endpoint of the line
    Point2 p2; ///< Second endpoint of the line

    /**
     * @brief Default constructor. Initializes the line with default points.
     */
    Line2();

    /**
     * @brief Parameterized constructor. Initializes the line with given points.
     * @param np1 The first endpoint of the line.
     * @param np2 The second endpoint of the line.
     */
    Line2(Point2 np1, Point2 np2);

    /**
     * @brief Calculates the length of the line segment.
     * @return The length of the line segment.
     */
    float length() const;

    /**
     * @brief Output operator for the Line2 class.
     * @param os The output stream.
     * @param line The line to be output.
     * @return The output stream.
     */
    friend ostream& operator<<(ostream& os, const Line2& line);
};

#endif // LINE2_H