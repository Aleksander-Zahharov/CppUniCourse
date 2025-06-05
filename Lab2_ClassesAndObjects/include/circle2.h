#ifndef CIRCLE2_H
#define CIRCLE2_H

#include "point2.h"
#include "line2.h"
#include <iostream>
using std::ostream;

/**
 * @class Circle2
 * @brief Represents a circle in the plane using the center p1 and a non-negative radius r.
 */
class Circle2 {
public:
    Point2 p1; ///< Center of the circle
    float r;   ///< Radius of the circle

    /**
     * @brief Default constructor. Creates a Circle2 with the center at the origin and radius 0.
     */
    Circle2();

    /**
     * @brief Parameterized constructor. Creates a Circle2 with the given center and radius.
     * @param np1 The center of the circle.
     * @param nr The radius of the circle. If a negative radius is provided, it is set to 0.
     */
    Circle2(Point2 np1, float nr);

    /**
     * @brief Calculates the circumference of the circle.
     * @return The circumference of the circle.
     */
    float circumference() const;

    /**
     * @brief Calculates the area of the circle.
     * @return The area of the circle.
     */
    float area() const;

    /**
     * @brief Checks if a given point is inside the circle.
     * @param p The point to check.
     * @return True if the point is inside the circle, false otherwise.
     */
    bool contains(Point2 p) const;

    /**
     * @brief Checks if a given line is inside the circle.
     * @param l The line to check.
     * @return True if the line is inside the circle, false otherwise.
     */
    bool contains(Line2 l) const;

    /**
     * @brief Scales the radius of the circle by the given factor.
     * @param factor The factor by which to scale the radius. If the factor is negative, the radius is not changed.
     */
    void scale(float factor);

    /**
     * @brief Output operator for the Circle2 class.
     * @param os The output stream.
     * @param circle The circle to output.
     * @return The output stream.
     */
    friend ostream& operator<<(ostream& os, const Circle2& circle);
};

#endif