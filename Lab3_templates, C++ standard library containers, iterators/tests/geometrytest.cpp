#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
#include "geometry.h" // Includes point.h, line.h, sphere.h, polugon.h and sum_vector.h inside
// #include "myfunctors.h"

#define COMMA ,	// To solve an issue in the TEST3 where "," is considered as a separator for a new argument and not the part of the code 
// Source: https://stackoverflow.com/questions/13842468/comma-in-c-c-macro
// Idk, this is brilliant, this is art. And kinda funny ahah

using namespace std;

int testcount = 0;
// This macro is used to test if two values are equal
#define TEST(a,b1,b2) \
	cout << "Test " << ++testcount << ". " << a << ": " << \
	(cmpf(b1,b2) ? "OK" :"FAIL") \
	<< endl
// This macro is used to test if two strings are equal
#define TEST2(a,b1,b2) \
	cout << "Test " << ++testcount << ". " << a << ": " << \
	(compStr(b1,b2) ? "OK" :"FAIL") \
	<< endl
// This macro is used to test if an exception is thrown
// 4th "Fail" line is executed if no exception is thrown and code went on. Should only happen if there is an equal amount of demensions in the two points
#define TEST3(a, code)\
    try {\
        code;\
        cout << "Test " << ++testcount << ". " << a << ": FAIL" << endl;\
    } catch (const std::string& e) {\
        cout << "Test " << ++testcount << ". " << a << ": OK (" << e << ")" << endl;\
    } catch (...) {\
        cout << "Test " << ++testcount << ". " << a << ": OK (Unknown exception)" << endl;\
    }

bool cmpf (float a, float b) {
	if (fabs (a - b) < 0.001f) 
		return true;
	return false;
}

bool compStr(string actual, string mustBe) { // just to ignore the spaces	
	actual.erase(remove_if(actual.begin(), actual.end(), ::isspace), actual.end());
	mustBe.erase(remove_if(mustBe.begin(), mustBe.end(), ::isspace), mustBe.end());
	return actual == mustBe || "(" + actual + ")" == mustBe;
}

int main (int argc, char* argv[]) {

	// -------------------- Task 1

	// -------------------- Point<n>
	cout << "---Testid Point<n> jaoks" << endl;

	// Require default constructor 
	Point<2> testPoint1;

	// Require member coords
	cout << testPoint1.coords.size() << endl;
	TEST("Point<2> vaikekonstruktor testPoint1.coords.size()(2)",	// message to the terminal
		testPoint1.coords.size(),									// actual output
		2);															// expected output	
	// Require constructor with parameters
	Point<2> testPoint2 { list<float>{5.0f, 6.0f} };
	// Require distanceFrom method
	float f = testPoint1.distanceFrom(testPoint1);
	TEST("Point<2> testPoint1.distanceFrom(testPoint1)(0)",
		f,
		0.0f);
	// Require toString method
	cout << testPoint1.toString () << endl;
	TEST2("Point<2> vaikekonstruktor testPoint1(0,0)",	// message to the terminal
		testPoint1.toString (),							// actual output
		"(0, 0)");										// expected output	
	// Require overloaded "<<" operators
	cout << testPoint1 << endl;



	// -------------------- My tests for task 1 Point:
	cout << "\n" << "---My tests for task 1.1 Point:" << endl;
	cout << testPoint2 << endl;

	// Point<3> v3 { list<float>{8.0f, 9.0f} };	// requires 3 coordinates but only 2 are given
	// TEST3: Check if an exception is thrown for incorrect number of coordinates
	TEST3("Point<3> constructor throws exception for wrong number of coordinates",
		Point<3> v3 { list<float>{8.0f COMMA 9.0f} }; // This should throw an exception
	);

	// Test - is it possible to create a point with 5 coordinates
	cout << "\n--Testing Point<5>--" << endl;

	// Create two points with 5 coordinates
	Point<5> testPoint3 { list<float>{1.0f, 2.0f, 3.0f, 4.0f, 5.0f} };
	Point<5> testPoint4 { list<float>{5.0f, 4.0f, 3.0f, 2.0f, 1.0f} };

	// Find the distance between them
	float distance = testPoint3.distanceFrom(testPoint4);
	TEST("Point<5> p1.distanceFrom(p2) == 6.324", distance, 6.324f);

	// Convert points to string
	std::string testPoint3Str = testPoint3.toString();
	std::string testPoint4Str = testPoint4.toString();
	TEST2("Point<5> p1.toString() == (1, 2, 3, 4, 5)", testPoint3Str, "(1, 2, 3, 4, 5)");
	TEST2("Point<5> p2.toString() == (5, 4, 3, 2, 1)", testPoint4Str, "(5, 4, 3, 2, 1)");

	// Output points to the terminal
	cout << "Point p1: " << testPoint3 << endl;
	cout << "Point p2: " << testPoint4 << endl;
	


	// -------------------- Line<V>
	cout << "\n" << "---Testid Line jaoks" << endl;
	// Require default constructor
	Line< Point<2> > testLine1;
	// Require constructor with two parameters
	Line< Point<2> > testLine2 {testPoint1, testPoint2};
	// Require members p1 and p2
	cout << testLine1.p1.toString() << "-" << testLine1.p2.toString () << endl;
	// Require method length
	f = testLine1.length();
	// Require toString method
	cout << testLine1.toString() << endl;
	// Require << operators
	cout << testLine1 << endl;





	// -------------------- Sphere<V>
	cout << "\n" << "---Testid Sphere jaoks" << endl;

	// Require default constructor
	Sphere<Point<2> > testSphere1;
	// Require variable o
	cout << testSphere1.o.toString();
	// Require variable r
	cout << testSphere1.r << endl;
	// Require toString method
	cout << testSphere1.toString () << endl;

	// Require constructor with vector and a radius
	Sphere< Point<2> > testSphere2 {testPoint1, 1.0};
	// Require method scale
	testSphere2.scale(2.0);
	// Require << operators
	cout << testSphere2 << " - radius should be doubled from 1.0" << endl;

	// Require method contains(Point<n>)
	bool b = testSphere1.contains(testPoint1);
    std::cout << std::boolalpha;	// Enable "True-False" output for boolean values
	cout << "Does contain the Point? - " << b << endl;
	// Require method contains(Line<Point<n>>)
	b = testSphere1.contains(testLine1);
	cout << "Does contain the Line? - "<< b << endl;
	
	


	// -------------------- Task 2 - Polygon
	cout << "\n" << "---Testid Task 2 jaoks" << endl;

	// Require default constructor
	Polygon<Point<2>, 3> testTriangle1;
	// Require method perimeter
	cout << "Triangle's perimeter:" << testTriangle1.perimeter() << endl;
	// Require toString method
	cout << "Triangle:" << testTriangle1.toString () << endl;
	// Require << operators
	cout << "Same triangle:" << testTriangle1 << endl;
	
	// Require constructor with parameters. 
	try {
		Polygon<Point<2>, 3> testTriangle2 {vector< Point<2> >{} }; // This should give an error, because the vector is empty, but requires 3 points
	} catch (const std::invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
	} catch (...) {
		cout << "Exception caught: Unknown exception" << endl;
	}
	
	// Lets create a square
	std::vector<Point<2>> testPoints1 = {
		Point<2>({1.0, 1.0}),
		Point<2>({2.0, 1.0}),
		Point<2>({2.0, 2.0}),
		Point<2>({1.0, 2.0})
	};
	// Require constructor with parameters
	Polygon<Point<2>, 4> testSquare1 {testPoints1};
	// Require << operators
	cout << "Square:" << testSquare1 << endl;
	cout << "Square Perimeter:" << testSquare1.perimeter() << endl;

	// Lets create a cube
	std::vector<Point<3>> testPoints2 = {
		// Lower face (base)
		Point<3>({1.0, 1.0, 1.0}),
		Point<3>({2.0, 1.0, 1.0}),
		Point<3>({2.0, 2.0, 1.0}),
		Point<3>({1.0, 2.0, 1.0}),
		// Upper face
		Point<3>({1.0, 1.0, 2.0}),
		Point<3>({2.0, 1.0, 2.0}),
		Point<3>({2.0, 2.0, 2.0}),
		Point<3>({1.0, 2.0, 2.0})
	};
	// Require constructor with parameters
	Polygon<Point<3>, 8> testCube1 {testPoints2};
	// Require << operators
	cout << "Cube:" << testCube1 << endl;

	// This should give an error, because the cube is 3D and the perimeter method is only available for 2D points
	try {
		// Attempt to calculate the perimeter of a 3D polygon (cube)
		cout << "Perimeter:" << testCube1.perimeter() << endl;
	} catch (const std::logic_error& e) {
		cout << "Exception caught while calculating perimeter: " << e.what() << endl;
	} catch (...) {
		cout << "Unknown exception caught while calculating perimeter." << endl;
	}



	/* Remove this comment to test the bonus task 3.1

	// Require object SumElements
	SumElements<float> sum;
	// Require operator ()
	sum (1.0);
	// Require method result
	float z = sum.result();

	Remove this comment to test the bonus task 3.1 */



	// --------------------Test the bonus task 3.2

	cout << "\n" << "---Testid Task 3.2 jaoks" << endl;

	vector<string> values {"a","b","c","d","e"};
    vector<int>    values1 {5,4,3,2,1}; 
    vector<float>  values2 {5.0f,4.0f,3.0f,2.0f,1.0f};

	TEST2("Sum should be: abcde",		// message to the terminal
		summeeri_malli_vektor(values),	// actual output
		"abcde");						// expected output	
	TEST("Sum should be: 15",
		summeeri_malli_vektor(values1),
		15);
	TEST("Sum should be: 15.000000",
		summeeri_malli_vektor(values2),
		15.000000f);

	
	
	cout << "\n" << "Testide arv: " << testcount << endl;
	return EXIT_SUCCESS;
}
