#include "functions.h"
#include <cmath>
#include <algorithm>

/**
 * @brief Returns the minimum of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The minimum of the two integers.
 */
long minimum(long a, long b) {
    return (a < b) ? a : b;
}

/**
 * @brief Returns the maximum of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The maximum of the two integers.
 */
long maximum(long a, long b) {
    return (a > b) ? a : b;
}

/**
 * @brief Returns the product of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The product of the two integers.
 */
long product(long a, long b) {
    return a * b;
}

/**
 * @brief Raises the first integer to the power of the second integer.
 * 
 * @param a Base.
 * @param b Exponent.
 * @return The result of raising the base to the power of the exponent. Returns 0 for negative exponents.
 */
long power(long a, long b) {
    if (b < 0) return 0; // Return 0 for negative powers
    return std::pow(a, b);
}
// We could use sth like next lines of code, to be able to insert negative numbers and get fractional numbers (with devision by 0 check),
// but "double power" would conflict with a "power" function from the cmath standard library.
// double power(long a, long b) {
//     if (a == 0 && b < 0) {
//         throw std::invalid_argument("Base cannot be zero when the exponent is negative.");
//     }
//     double result = std::pow(a, b);
    
//     // Limit the result to 5 decimal places
//     std::ostringstream out;
//     out << std::fixed << std::setprecision(5) << result;
//     return std::stod(out.str());
// }

/**
 * @brief Returns the greatest common divisor of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The greatest common divisor of the two integers.
 */
long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}