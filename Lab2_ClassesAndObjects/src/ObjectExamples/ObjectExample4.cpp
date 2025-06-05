#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle {
    public:
        int width, height;
        int surface() {
            return width*height;
        }
};

int main () {
    Rectangle rect1;
    rect1.width = 5;
    rect1.height = 6;
    int surface1 = rect1.surface();
    Rectangle rect2;
    rect2.width = 3;
    rect2.height = 4;
    int surface2 = rect2.surface();

    cout << "surface 1 -> " << surface1 << ", surface 2 -> " << surface2 << "\r\n";
    return EXIT_SUCCESS;
}