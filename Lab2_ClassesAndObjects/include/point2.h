#ifndef POINT2_H
#define POINT2_H

#include <iostream>
using std::ostream;

/**
 * @class Point2
 * @brief Represents a point in 2D space.
 */
class Point2 {
public:
    float x = 0; ///< Member variable for x-coordinate
    float y = 0; ///< Member variable for y-coordinate

    /**
     * @brief Default constructor. Initializes the point at the origin (0, 0).
     */
    Point2();

    /**
     * @brief Parameterized constructor. Initializes the point with given coordinates.
     * @param nx The x-coordinate of the point.
     * @param ny The y-coordinate of the point.
     */
    Point2(float nx, float ny);

    /**
     * @brief Calculates the distance from another point.
     * @param p The other point.
     * @return The distance from the other point.
     */
    float distanceFrom(Point2 p) const;

    /**
     * @brief Overloaded output operator for the Point2 class.
     * @param os The output stream.
     * @param p The point to be output.
     * @return The output stream.
     */
    friend ostream& operator<<(ostream& os, const Point2& p);
};

#endif // POINT2_H