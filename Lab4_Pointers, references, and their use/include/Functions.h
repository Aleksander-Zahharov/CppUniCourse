#ifndef SOLVEEQUATION_H
#define SOLVEEQUATION_H

/**
 * @brief Swaps the values of two variables using references.
 * 
 * @tparam T The type of the variables.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template<class T> 
void swap_ref(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Swaps the values of two variables using pointers.
 * 
 * @tparam T The type of the variables.
 * @param a Pointer to the first variable.
 * @param b Pointer to the second variable.
 */
template<class T> 
void swap_ptr(T *a, T *b) {
    if (a && b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}

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
bool solve(double a, double b, double c, double &x1, double &x2);

#endif