#include <windows.h> // Добавил, все начало работать
#include <iostream>
#include <vector>
#include <string>
#include <consoleapi2.h>
#include <winnls.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8); // Эта строчка позволяет отображать русские символы в консоли. 
                                // Для стандартного HelloWorld она не нужна
    std::cout << std::endl << "Hello, World! 7 привет" << std::endl;

    // Еще одно сообщение
    vector<string> messagE {"Hello", "C++", "World", "from", 
                        "VS Code", "and the C++ extension!"};
    for (const string& worD : messagE){
        cout << worD << " ";
    }
    cout << endl;
}

