/* See on peaprogramm, mis algab funktsioonis 'main'. */
#include <iostream> /* Sisend ja väljund */
#include <cstdlib>  /* EXIT_SUCCESS jt konstandid */
#include "functions.h" /* Meie oma funktsioonid */
#include <limits>
using namespace std; /* Nimeruumi valik (selgitatakse praktikumis) */

int main(int argc, char *argv[]) {
  
  // TODO: Kirjutage peaprogrammi kasutajaliides

  // This program is a simple pet simulator. It allows the user to pet a dog or a cat.
  int choice;
  cout << endl << "Welcome to the program!" << endl;
  do {
  cout << endl << "Options:" << endl;
  cout << "1. Pet the Dog" << endl;
  cout << "2. Pet the Cat" << endl;
  cout << "3. Exit" << endl;

  cout<< endl << "Enter your choice: ";
  while (!(cin >> choice)) { // Choice must be an integer. Otherwise we get FALSE. With ! it becomes TRUE.
    cin.clear(); // clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    cout << "Invalid input! Please enter a number: ";
  }

  switch(choice) {
  case 1:
    cout << "You pet the dog. It wags its tail happily." << endl;
    break;
  case 2:
    cout << "You pet the cat. It purrs contentedly." << endl;
    break;
  case 3:
    cout << "Exiting the program." << endl;
    break;
  default:
    cout << "Invalid choice! Only 1, 2 or 3" << endl;
    break;
  }
  } while (choice != 3);
  
  return EXIT_SUCCESS;
}
