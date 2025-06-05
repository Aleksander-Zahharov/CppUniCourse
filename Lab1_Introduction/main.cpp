// Задание: https://courses.cs.ut.ee/2025/cppeng/spring/Main/Lab01
/* This is the main program that starts in the 'main' function. */
#include <iostream> /* Input and output */
#include <cstdlib>  /* EXIT_SUCCESS and other constants */
#include "functions.h" /* Our own functions */

#include <limits>
#include <string.h>
#include <cctype>
#include <sstream>
#include <fstream>
using namespace std; /* Namespace selection (explained in the practical) */

/**
 * @brief Checks if the string is a number.
 * 
 * @param str The string to check.
 * @return True if the string is a number, false otherwise.
 */
bool isNumber(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    cout << endl << "Enter your function like: 'program' NUM NUM (name of the function)" << endl 
    << "Available functions: minimum, maximum, product, power, gcd (or *nothing*)" << endl
    << "OR type a file name to read numbers from .txt file" << endl;

    string usrInput;
    getline(cin, usrInput); // Input from cin will be stord in usrInput
    long a, b; // The two numbers that the user will insert

    // Lets parse the input and insert arguments into the array.
    istringstream iss(usrInput); // Split the string by spaces
    string usrInputArgs[4];
    int i = 0;  // Counter for the number of arguments inserted by user
    while (iss >> usrInputArgs[i] && i < 4) { // Counting the number of arguments inserted by user
        i++;
    } // Now i is the number of arguments and usrInputArgs contains them



    // (BONUS TASK) Check if there is only one argument, then it is a file name. 
    // Parse the file and insert the numbers into the usrInputArgs array.
    if (i == 1) {
        string fileName = usrInputArgs[0] + ".txt";
        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "Error: File with the name '" << fileName << "' does not exist in the root folder of this project" << endl;
            return EXIT_FAILURE;
        }

        if (!(inputFile >> a >> b)) { // Read the first two numbers from the file and write them to a and b
            cerr << "Error: File does not contain two numbers!" << endl;
            return EXIT_FAILURE;
        }
        // Rewriting usrInputArgs, so that the program could proceed as usual
        usrInputArgs[0] = "program";
        usrInputArgs[1] = to_string(a);
        usrInputArgs[2] = to_string(b);
        i = 3; // Update the number of arguments
    } // Proceed program as usual



    if (i < 3 || i > 4) { /* Check if there are enough parameters. Task needs 3 or 4 (or 1 to read file) */
        cerr << "Error: Wrong number of command line parameters!" << endl;
        return EXIT_FAILURE;
    }
    if (usrInputArgs[0] != "program") { /* Check if the first argument is "program" */
        cerr << "Error: 1st argument should be 'program'" << endl;
        return EXIT_FAILURE;
    }
    if (!isNumber(usrInputArgs[1]) || !isNumber(usrInputArgs[2])) { /* Check if the second and third arguments are numbers */
        cerr << "Error: 2nd and 3rd arguments should be numbers" << endl;
        return EXIT_FAILURE;
    }

    a = atol(usrInputArgs[1].c_str()); /* Convert text to number */
    b = atol(usrInputArgs[2].c_str());

    cout << a << " " << b << endl; // Output the inserted numbers, as the task needs

    // We can use if-else or map or unordered_map
    if (i == 4) { // If we have 4 arguments
        if (usrInputArgs[3] == "minimum")
            cout << minimum(a, b) << endl;
        else if (usrInputArgs[3] == "maximum")
            cout << maximum(a, b) << endl;
        else if (usrInputArgs[3] == "product")
            cout << product(a, b) << endl;
        else if (usrInputArgs[3] == "power")
            cout << power(a, b) << endl;
        else if (usrInputArgs[3] == "gcd")
            cout << gcd(a, b) << endl;
        else {
            cerr << "Error: Unknown function name!" << endl;
            return EXIT_FAILURE;
        }
    } else {  // The only variant left is if we have 3 usrInputArgs, and i=3
        cout << minimum(a, b) << endl;
        cout << maximum(a, b) << endl;
        cout << product(a, b) << endl;
        cout << power(a, b) << endl;
        cout << gcd(a, b) << endl;
    }

    return EXIT_SUCCESS;
}