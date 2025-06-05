#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

// Task 1: Constants
// With "#define":
// the value is substituted at the preprocessing stage without type checking,
// which makes debugging more difficult.
// And Area = 452.388947
// With constant:
// the variable is checked by the compiler, ensures type control,
// and simplifies debugging.
// And Area = 452.388977
#define PI 3.14159


// Task 2: Find the minimum and maximum of two numbers using macros
#define PRINT_RESULT(a, b, op) \
	if (op == "min") { \
		cout << "Minimum: " << ((a < b) ? a : b) << endl; \
	} else if (op == "max") { \
		cout << "Maximum: " << ((a > b) ? a : b) << endl; \
	} else { \
		cerr << "Error: Invalid operation. Use 'min' or 'max'." << endl; \
	}


// Task 3: Equivalence classes and boundary value analysis

bool isValidInput(const std::string& input) {
    // Check if the input is a number
    for (char c : input) {
        if (!std::isdigit(c)) {
            return false;	// If at least one character is not a digit, return false
        }
    }
    // Convert to integer and check range
    int value = std::stoi(input);	//stoi - String to integer
    return value >= 1 && value <= 99;	// Return true if in the range [1, 99]
}

// Define valid pizza types
bool isValidType(const std::string& type) {
    // Accept only known pizza types
    return type == "Margherita" || type == "Pepperoni" || type == "Vegetarian";
}

// Equivalence classes and boundary value analysis for pizza order inputs:
// 1. Count below minimum (<1)
// 2. Count at minimum (1)
// 3. Count typical (50)
// 4. Count at maximum (99)
// 5. Count above maximum (>99)
// 6. Non-numeric count input
// 7. Valid pizza types and invalid types (letters vs strange symbols like "!№;%")

// Test macro for BVA and type validation
#define TEST_INPUT(count, type, expCountValid, expTypeValid) \
    do { \
        bool cnt = isValidInput(count); \
        bool tp  = isValidType(type);  \
        cout << "Test(count=" << count << ", type=" << type << "): " \
             << "count valid? " << (cnt ? "true" : "false") << " (exp " << (expCountValid ? "true" : "false") << "), " \
             << "type valid? "  << (tp  ? "true" : "false") << " (exp " << (expTypeValid  ? "true" : "false") << ")" \
             << ((cnt == expCountValid && tp == expTypeValid) ? " => OK" : " => FAIL") \
             << endl; \
    } while(0)

// Task 4:
#define DOCTEST_CONFIG_IMPLEMENT // To run custom main with tests
#include "doctest.h"

// Task 4: Using doctest to verify parseCount function
int parseCount(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c)) throw std::string("invalid input");
    }
    int val = std::stoi(input);
    if (val < 1 || val > 99) throw std::string("invalid input");
    return val;
}

TEST_CASE("Task4: parseCount valid values") {
    CHECK(parseCount("1") == 1);
    CHECK(parseCount("50") == 50);
    CHECK(parseCount("99") == 99);
}

TEST_CASE("Task4: parseCount invalid values") {
    CHECK_THROWS_AS(parseCount("0"), std::string);
    CHECK_THROWS_AS(parseCount("100"), std::string);
    CHECK_THROWS_AS(parseCount("abc"), std::string);
    CHECK_THROWS_AS(parseCount("!№;%"), std::string);
}


int main(int argc, char* argv[])
{
	// Task 1: Constants
	cout << "\nTask 1:" << endl;
	float radius, area;
	// float PI = 3.14159;
	radius = 12;
	area = PI * radius * radius;
	printf("Area = %f", area);


	// Task 2: Find the minimum and maximum of two numbers using macros
	cout << "\n\nTask 2:" << endl;
	float num1, num2;
	string operation;
	cout << "Enter first number: ";
	while (!(cin >> num1)) {
		cerr << "Invalid input. Please enter a valid float number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Enter second number: ";
	while (!(cin >> num2)) {
		cerr << "Invalid input. Please enter a valid float number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Enter operation (min/max): ";
	while (true) {
		cin >> operation;
		if (operation == "min" || operation == "max") {
			break;
		} else {
			cerr << "Invalid input. Please enter 'min' or 'max': ";
		}
	}

	PRINT_RESULT(num1, num2, operation);


	// Task 3: Equivalence classes and boundary value analysis
	// Automated tests for Task 3 - Equivalence classes and BVA
	cout << "\nTests for Task 3:" << endl;
    TEST_INPUT("0", "Margherita", false, true);    // count below min
    TEST_INPUT("1", "Margherita", true, true);     // count at min
    TEST_INPUT("50", "Margherita", true, true);    // typical count
    TEST_INPUT("99", "Margherita", true, true);    // count at max
    TEST_INPUT("100", "Margherita", false, true);  // count above max
    TEST_INPUT("abc", "Margherita", false, true);  // non-numeric count
    TEST_INPUT("50", "Unknown", true, false);      // invalid pizza type
    TEST_INPUT("50", "!№;%", true, false);         // invalid symbols


	// Task 4:
	// Tested via doctest
	cout << "\nTask 4:" << endl;
 	doctest::Context ctx;                     // create doctest context
    ctx.applyCommandLine(argc, argv);         // apply command line
    int res = ctx.run();                      // run tests
    if(ctx.shouldExit()) return res;          // exit if --exit or tests failed

	return 0;
}