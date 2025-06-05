#ifndef DYNAMICLINE_H
#define DYNAMICLINE_H

/**
 * @brief Template class representing a line with endpoints defined by pointers.
 * 
 * @tparam T The type of the points.
 */
template<class T>
class DynamicLine {
public:
    /**
     * @brief Parameterized constructor to initialize the line with two endpoints.
     * 
     * @param v1 Pointer to the first endpoint.
     * @param v2 Pointer to the second endpoint.
     */
    DynamicLine(T *v1, T *v2) : p1(v1), p2(v2) {}

    /**
     * @brief Copy constructor. Copies the line without creating new points.
     * 
     * @param l The line to copy.
     */
    DynamicLine(const DynamicLine &l) : p1(l.p1), p2(l.p2) {}

    /**
     * @brief Assignment operator. Copies the line without creating new points.
     * 
     * @param l The line to assign.
     * @return Reference to the current object.
     */
    DynamicLine& operator=(const DynamicLine &l) {
        if (this != &l) {
            p1 = l.p1;
            p2 = l.p2;
        }
        return *this;
    }

    /**
     * @brief Destructor. Does not release memory for endpoints.
     */
    ~DynamicLine() {}

    T *p1; ///< Pointer to the first endpoint.
    T *p2; ///< Pointer to the second endpoint.
};

#endif // DYNAMICLINE_H