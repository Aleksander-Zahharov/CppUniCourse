#include <iostream>
#include <cstdlib>
using namespace std;

int surface(int w, int h) {
    return w*h;
}

int main () {
    int w1=5;
    int h1=6; 
    int surface1 = surface(w1,h1) ;
    int w2=3;
    int h2=4;
    int surface2 = surface(w2,h2) ;

    cout << "surface 1 -> " << surface1 << ", surface 2 -> " << surface2 << "\r\n";
    return EXIT_SUCCESS;
}