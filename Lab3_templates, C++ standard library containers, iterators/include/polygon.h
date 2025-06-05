#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "point.h"

/**
 * @brief Class template for an n-point polygon.
 * @tparam T Type of the points (e.g., Point<n>).
 * @tparam m Number of points in the polygon.
 */
template <class T, unsigned short m>
class Polygon {
	// Ensure that T is either Point<2> or Point<3>
    static_assert(
        std::is_same<T, Point<2>>::value || std::is_same<T, Point<3>>::value,
        "Template parameter T must be Point<2> or Point<3>."
    );
	
public:
    std::vector<T> points; ///< Points of the polygon.
	// !!! For me: std::vector — это шаблонный класс из стандартной библиотеки C++ (STL), который представляет собой динамический массив.
	// Он позволяет хранить элементы одного типа и автоматически изменяет свой размер при добавлении или удалении элементов.
	// То-есть, vector<T> используется для хранения набора точек (Point<n>) в массиве, который может динамически изменять размер.

    /**
     * @brief Default constructor. Initializes all points with default values.
	 * T is from <Point<n>> and m is from 2nd template parameter.
	 * We can create default constructor like: 
	 * Polygon<Point<2>, 3> triangle;
     */
    Polygon() : points(m, T()) {}	//m and T() can be swapped places

    /**
     * @brief Parameterized constructor. Initializes the polygon with given points.
     * @param pts Vector of points.
     * @throws std::invalid_argument if the size of pts does not match n.
	 * We can create vector like:
	 * std::vector<Point<2>> points = {Point<2>({1.0, 2.0}), Point<2>({3.0, 4.0}), Point<2>({5.0, 6.0})};
	 * We create this constructor like:
	 * Polygon<Point<2>, 3> triangle2 {vector< Point<2> >{} }
     */
    Polygon(const std::vector<T>& pts) {
        if (pts.size() != m) {
            throw std::invalid_argument("Number of points does not match the polygon's dimension.");
        }
        points = pts;
    }

	/**
	 * @brief Calculates the perimeter of the polygon.
	 * @return Perimeter of the polygon.
	 * @note This method is only available for 2D points (Point<2>).
	 */
	float perimeter() const {
		if constexpr (!std::is_same<T, Point<2>>::value) {
			throw std::logic_error("Perimeter calculation is only available for Point<2>.");
		}
		float sum = 0.0f;
		for (unsigned short i = 0; i < m; ++i) {
			sum += points[i].distanceFrom(points[(i + 1) % m]); // Connects the last point to the first point
		}
		return sum;
	}

    /**
     * @brief Converts the polygon to a string representation.
     * @return String representation of the polygon.
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "(";
        for (unsigned short i = 0; i < m; ++i) {
            if (i > 0) oss << ", ";
            oss << points[i].toString();
        }
        oss << ")";
        return oss.str();
    }

    /**
     * @brief Overloads the << operator for output.
     * @param os Output stream.
     * @param polygon Polygon to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon<T, m>& polygon) {
        os << polygon.toString();
        return os;
    }
};

#endif // POLYGON_H