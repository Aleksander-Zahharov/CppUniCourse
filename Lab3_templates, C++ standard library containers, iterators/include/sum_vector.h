#ifndef SUM_VECTOR_H
#define SUM_VECTOR_H

#include <vector>
#include <algorithm>
using namespace std;

/** @brief Template function to sum elements of a vector using a lambda function.
 *
 * Example usage:
 * @code
 * vector<string> values {"a", "b", "c", "d", "e"};       // vector of letters/words
 * vector<int> values1 {5, 4, 3, 2, 1};                                // vector of ints
 * vector<float> values2 {5.0f, 4.0f, 3.0f, 2.0f, 1.0f};               // vector of floats
 *
 * cout << "Sum is: " << summeeri_malli_vektor(values)  << endl; // prints "Sum is abcde"
 * cout << "Sum is: " << summeeri_malli_vektor(values1) << endl; // prints "Sum is 15"
 * cout << "Sum is: " << summeeri_malli_vektor(values2) << endl; // prints "Sum is 15.000000"
 * @endcode
 */
template <typename T>
T summeeri_malli_vektor(vector<T> vec) {
	// Initialize the sum variable with the default value of type T
	T sum = T();

	// Use for_each with a lambda function to calculate the sum
	for_each(vec.begin(), vec.end(), [&sum](const T& element) {
		sum += element; // Add each element to the sum
	});

	return sum; // Return the calculated sum
}

#endif // SUM_VECTOR_H