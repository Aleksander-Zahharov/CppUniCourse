/**
 * @file geometrytest.cpp
 * @brief This file contains tests for the Point2, Line2, and Circle2 classes.
 * 
 * Tasks: https://courses.cs.ut.ee/2025/cppeng/spring/Main/Lab02assignment
 */

 #include <iostream>
 #include <sstream>
 #include <cstdlib>
 #include <cmath> // fabs
 #include "../include/geometry.h" 
 
 using namespace std;
 
 int testcount = 0;
 
 /**
  * @brief Macro for testing equality of floating-point numbers.
  * 
  * @param a Test description.
  * @param b First value to compare.
  * @param b2 Expected value for the first value.
  * @param c Second value to compare.
  * @param c2 Expected value for the second value.
  */
 #define TEST2(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " << ((cmpf(b,b2) && cmpf(c,c2)) ? "OK" :"FAIL") << endl
 
 /**
  * @brief Compares two floating-point numbers for equality within a small tolerance.
  * 
  * @param a First floating-point number.
  * @param b Second floating-point number.
  * @return true if the numbers are equal within the tolerance, false otherwise.
  */
 bool cmpf (float a, float b) {
	 if (fabs (a - b) < 0.001f) 
		 return true;
	 return false;
 }
 
 /**
  * @brief Main function to run the tests.
  * 
  * @param argc Argument count.
  * @param argv Argument vector.
  * @return int Exit status.
  */
 int main (int argc, char* argv[]) {
 
	 // Point2
	 cout << "--Testing class Point2" << endl;
	 // Testing default constructor
	 Point2 xy1;
	 cout << xy1.x << " " << xy1.y << endl;
	 TEST2("Default constructor Point2 xy1(0,0)", xy1.x, 0, xy1.y, 0);
 
	 // Testing parameterized constructor
	 Point2 xy2 {1.0, -1.0}; // c++11 
	 TEST2("Parameterized constructor Point2 xy2(1,-1)", xy2.x, 1, xy2.y, -1);
 
	 // Testing distanceFrom method
	 float distance = xy1.distanceFrom(xy2);
	 cout << "Distance from xy1 to xy2: " << distance << endl;
	 TEST2("Method distanceFrom", distance, sqrt(2), 0, 0);
 
	 // Testing operator <<
	 cout << "Coordinates of point xy1: " << xy1 << endl;
	 cout << "Coordinates of point xy2: " << xy2 << endl;
 
	 cout << xy1 << endl;
 
	 // Line2
	 cout << "\n Line2 tests" << endl;
	 // Require default constructor
	 Line2 l1;
	 // Require public points p1 and p2
	 cout << l1.p1 << "-" << l1.p2 << endl;
	 // Require constructor with two parameters
	 Line2 l2 {xy1, xy2};
	 // Require method length
	 cout << l1.length() << endl;
	 // Require operator <<
	 cout << l1 << endl;
 
	 // Circle2
	 cout << "\nCircle2 tests" << endl;
	 // Require default constructor
	 Circle2 c1;
	 // Require variable p1
	 cout << c1.p1 << endl;
	 // Require variable r
	 cout << c1.r << endl;
	 // Require constructor with point and a radius
	 Circle2 c2 {xy1, 1.0};
	 // Require method circumference
	 float f = c1.circumference();
	 cout << "Circumference: " << f << endl;
	 // Require method area
	 f = c1.area();
	 // Require method contains(Point2)
	 bool b = c1.contains(xy1);
	 cout << boolalpha; // Turns on "true/false" output for boolean (instead of 1 or 0)
	 cout << "Circle contains that Point: " << b << endl;
	 // Require method contains(Line2)
	 b = c1.contains(l1);
	 cout << "Circle contains that Line: " << b << endl;
	 // Require method scale
	 c1.scale(1.0);
	 // Require operator <<
	 cout << c1 << endl;
 
	 /* Remove this comment to test the bonus task
 
	 // Point3
	 // Require default constructor
	 Point3 v3_1;
	 // Require public coordinates x, y and z
	 cout << v3_1.x << " " << v3_1.y << " " << v3_1.z << endl;
	 // Require constructor with three parameters
	 Point3 v3_2 {1.0, 0.0, -1.0};
	 // Require method distanceFrom
	 f = v3_1.distanceFrom (v3_2);
	 // Require operator <<
	 cout << v3_1 << endl;
 
	 // Line3
	 // Require default constructor
	 Line3 l3_1;
	 // Require constructor with two parameters
	 Line3 l3_2 {v3_1, v3_2};
	 // Require method length
	 f = l3_1.length();
	 // Require operator <<
	 cout << l3_1 << endl;
 
	 // Sphere3
	 // Require default constructor
	 Sphere3 s3_1;
	 // Require constructor with point and a radius
	 Sphere3 s3_2 {v3_1, 1.0};
	 // Require method circumference
	 f = s3_1.circumference();
	 // Require method volume
	 f = s3_1.volume();
	 // Require method contains(Point3)
	 b = s3_1.contains(v3_1);
	 // Require method contains(Line3)
	 b = s3_1.contains(l3_1);
	 // Require method scale
	 s3_1.scale(1.0);
	 // Require operator <<
	 cout << s3_1 << endl;
 
	 Remove this comment to test the bonus task */   
 
	 cout << "\nTotal number of tests: " << testcount << endl << endl;
	 return EXIT_SUCCESS;
 }