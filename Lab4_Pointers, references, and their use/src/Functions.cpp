#include "Functions.h"
#include <cmath>

/**
 * @brief Solves a quadratic equation of the form ax^2 + bx + c = 0.
 * 
 * @param a Coefficient of x^2.
 * @param b Coefficient of x.
 * @param c Constant term.
 * @param x1 Reference to store the first root.
 * @param x2 Reference to store the second root.
 * @return true if the equation has real roots, false otherwise.
 */
bool solve(double a, double b, double c, double &x1, double &x2) {
    // Case 1: Linear equation (a == 0)
    if (a == 0) {
        if (b == 0) {
            // No solution if both a and b are 0
            return false;
        }
        // Linear equation bx + c = 0
        x1 = -c / b;
        x2 = x1; // Both roots are the same for linear equations
        return true;
    }

    // Case 2: Quadratic equation (a != 0)
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No real roots if the discriminant is negative
        return false;
    } else if (discriminant == 0) {
        // One real root if the discriminant is zero
        x1 = x2 = -b / (2 * a);
        return true;
    } else {
        // Two real roots if the discriminant is positive
        x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return true;
    }
}

// Explicit template instantiations for swap_ref and swap_ptr

/**
 * @brief Explicit instantiation of swap_ref for integers.
 */
template void swap_ref<int>(int &a, int &b);

/**
 * @brief Explicit instantiation of swap_ptr for integers.
 */
template void swap_ptr<int>(int *a, int *b);

/**
 * @brief Explicit instantiation of swap_ref for doubles.
 */
template void swap_ref<double>(double &a, double &b);

/**
 * @brief Explicit instantiation of swap_ptr for doubles.
 */
template void swap_ptr<double>(double *a, double *b);