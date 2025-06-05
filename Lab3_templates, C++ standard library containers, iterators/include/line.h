#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <sstream>
#include "geometry.h" // Includes point.h inside

/**
 * @brief Class template for a straight line segment.
 * @tparam T Type of the points (e.g., Point<n>).
 */
template <class T> class Line {
public:
    T p1; //< First vertex of the line.
    T p2; //< Second vertex of the line.

    /**
     * @brief Default constructor. Creates a line with default points.
     */
    Line() : p1(T()), p2(T()) {}

    /**
     * @brief Parameterized constructor. Initializes the line with two points.
     * @param np1 First point.
     * @param np2 Second point.
     */
    Line(T np1, T np2) : p1(np1), p2(np2) {}

    /**
     * @brief Calculates the length of the line.
     * @return Length of the line.
     */
    float length() const {
        return p1.distanceFrom(p2);
    }

    /**
     * @brief Converts the line to a string representation.
     * @return String representation of the line.
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "(" << p1.toString() << "-" << p2.toString() << ")";
        return oss.str();
    }

    /**
     * @brief Overloads the << operator for output.
     * @param os Output stream.
     * @param line Line to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Line<T>& line) {
        os << line.toString();
        return os;
    }
};

#endif // LINE_H