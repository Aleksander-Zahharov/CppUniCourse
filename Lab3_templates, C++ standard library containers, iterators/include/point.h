#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <list>
#include <cmath>
#include <sstream>
#include <stdexcept>

/**
 * It was possible to separate point.h and point.cpp files, but it would be more difficult to use the template class
 * in other files, so I decided not to have point.cpp-file and to keep the implementation in this header file.
 * 
 * @brief Class template for a point in n-dimensional space.
 * @tparam n Number of dimensions.
 */
template <unsigned short n> 
class Point {
public:
    std::list<float> coords; ///< Coordinates of the point.

    /**
     * @brief Default constructor. Initializes all coordinates to 0.
     */
    Point() : coords(n, 0.0f) {}

    /**
     * @brief Constructor with a list of coordinates.
     * @param crds List of coordinates.
     * @throws std::string if the size of crds does not match n.
     */
    Point(std::list<float> crds) {
        if (crds.size() != n) {
			// std::cerr << "Error: Number of coordinates does not match the dimension." << std::endl;	// We can see this message in the terminal before the program terminates
            throw std::string("Number of coordinates does not match the dimension.");	// We will see this error message if we use try-catch block in the main function.
			// Otherwise, the program will terminate and we will not see this error message.
        }
        coords = crds;
    }

    /**
     * @brief Calculates the distance from another point.
     * @param v Another point of the same dimension.
     * @return Distance between the points.
     */
    float distanceFrom(const Point<n>& v) const {
		if (coords.size() != v.coords.size()) {
			throw std::invalid_argument("Points must have the same number of dimensions (same size of the lists of the coordinates).");
		}	// Check if the sizes of two lists of coordinates are equal

        auto it1 = coords.begin();	// auto it1 automatically gets the type of the iterator for the beginning element of the list "coords" in the current object
        auto it2 = v.coords.begin();// auto it2 automatically gets the type of the iterator for the beginning element of the list "v.coords" in the object v
        float sum = 0.0f;

        while (it1 != coords.end()) {
            sum += std::pow((*it1 - *it2), 2);	// Pointers *it1 and it2 are dereferenced to get the values of their lists of coordinates
				// The difference between the two coordinates is squared and added to the sum
            ++it1;	// Moves the iterator it1 to the next element in the list coords
            ++it2;	// Moves the iterator it2 to the next element in the list v.coords
        }
        return std::sqrt(sum); // Return the square root of the sum (of squares) to get the distance
    }

    /**
     * @brief Converts the point to a string representation.
     * @return String representation of the point.
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "(";
        for (auto it = coords.begin(); it != coords.end(); ++it) {
            if (it != coords.begin()) oss << ", ";
            oss << *it;
        }
        oss << ")";
        return oss.str();
    }

    /**
     * @brief "Overloads"(/Changes) the standard "<<" operator's behaviour to print the coordinates in the coords list of this object(this Point).
     * @param os Output stream.
     * @param point Point to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Point<n>& point) {
        os << point.toString();
        return os;
	}	// The "operator<<" function is defined as a "friend" of the Point class, allowing it to access private members like coords or other private methods of the Point class.
	// Now if we use "<<" operator on a Point object, it will call this function and print the coordinates in the format defined in the toString() method. Like this:
	// Point<5> p;
	// std::cout << p << std::endl;
	// Output in the concole: (0, 0, 0, 0, 0)

};

// Explicit template instantiations
template class Point<1>;
template class Point<2>;
template class Point<3>;

// Destructor is not needed here as std::list will automatically clean up its elements when this object is destroyed.

#endif // POINT_H