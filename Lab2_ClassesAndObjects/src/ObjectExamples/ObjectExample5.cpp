#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle {
    public:
        int width, height;

        int getSurface() {  	// Getting the surface of the rectangle
            return width*height;
        }

        void setWidth(int w) {  // Setting the width of the rectangle
            if (w > 0){
                width = w;
            }else{
                cout << "Width must be greater than 0" << "\r\n";
            }
        }
        int getWidth() {    	// Getting the width of the rectangle
            return width;
        }

        void setHeight(int h) { // Setting the height of the rectangle
            if (h > 0){
                height = h;
            }else{
                cout << "Height must be greater than 0" << "\r\n";
            }
        }
        int getHeight() {  		// Getting the height of the rectangle
            return height;
        }

        void setWidthAndHeight(int w, int h) {  // Setting the width and height of the rectangle
            setWidth(w);
            setHeight(h);
        }

        // Constructors
        Rectangle(int w, int h) {
            setWidth(w);
            setHeight(h);
        }
        Rectangle() : Rectangle(1,1) {}    // Default constructor
        // Destructor
        ~Rectangle() {
            cout << "Rectangle destroyed" << "\r\n";
        }

};

int main () {
    Rectangle rect1;
    cout << rect1.getSurface() << "\r\n";
    cout << "CHECK1" << "\r\n";
    rect1.width = 5;
    rect1.height = 6;
    int surface1 = rect1.getSurface();
    Rectangle rect2;
    rect2.setHeight(3);
    rect2.setWidth(4);
    int surface2 = rect2.getSurface();
    Rectangle rect3;
    rect3.setWidthAndHeight(5, 5);

    cout << "surface 1 -> " << surface1 << ", surface 2 -> " << surface2 << ", surface 3 -> " << rect3.getSurface() << "\r\n";
    
    // rect1.~Rectangle();
    // rect2.~Rectangle();
    // rect3.~Rectangle();

    return EXIT_SUCCESS;
}