#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <sstream>
#include <cmath>
#include "geometry.h" // Includes point.h and line.h inside

/**
 * @brief Class template for a sphere (or circle in 2D).
 * @tparam T Type of the midpoint (e.g., Point<n>). 
 */
template <class T>
class Sphere {
	// Constraint: T must be either Point<2> or Point<3>
	static_assert(
		std::is_same<T, Point<2>>::value || 
		std::is_same<T, Point<3>>::value,
		"Template parameter T must be Point<2> or Point<3>."
	);

public:
	T o; ///< Midpoint of the sphere.
    float r; ///< Radius of the sphere.

    /**
     * @brief Default constructor. Creates a sphere with midpoint at the origin and radius 0.
     */
    Sphere() : o(T()), r(0.0f) {}

    /**
     * @brief Parameterized constructor. Initializes the sphere with a midpoint and radius.
     * @param no Midpoint of the sphere.
     * @param nr Radius of the sphere.
     * @throws std::invalid_argument if the radius is negative.
     */
    Sphere(T no, float nr) : o(no), r(nr) {
        if (nr < 0.0f) {
            throw std::invalid_argument("Radius cannot be negative.");
        }
    }

    /**
     * @brief Checks if a point is inside or on the sphere.
     * @param v Point to check.
     * @return True if the point is inside or on the sphere, otherwise false.
     */
    bool contains(T v) const {
        return o.distanceFrom(v) <= r;
    }

    /**
     * @brief Checks if a line is completely inside the sphere.
     * @param l Line to check.
     * @return True if the line is inside the sphere, otherwise false.
     */
    bool contains(Line<T> l) const {
        return contains(l.p1) && contains(l.p2);
    }

    /**
     * @brief Scales the radius of the sphere by a given factor.
     * @param factor Scaling factor.
     * @throws std::invalid_argument if the factor is negative.
     */
    void scale(float factor) {
        if (factor < 0.0f) {
            throw std::invalid_argument("Scaling factor cannot be negative.");
        }
        r *= factor;
    }

    /**
     * @brief Converts the sphere to a string representation.
     * @return String representation of the sphere.
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "((" << o.toString() << "), " << r << ")";
        return oss.str();
    }

    /**
     * @brief Overloads the << operator for output.
     * @param os Output stream.
     * @param sphere Sphere to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Sphere<T>& sphere) {
        os << sphere.toString();
        return os;
    }
};

#endif // SPHERE_H