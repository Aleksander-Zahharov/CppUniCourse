#include <iostream>

#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // Позволяет отображать русские символы в консоли. Для стандартного HelloWorld она не нужна
    std::cout << "\nHello, World! Привет! 004 " << std::endl;

    return 0;
}

// Ctrl+Shift+P -> Run Task -> "Обычный таск: Скомпилировать HelloWorld0 (без Makefile)"
// Или через Makefile:
// Ctrl+Shift+P -> Run Task -> "Make: build and run HelloWorld0 !!1" - компилирует и запускает программу
// Ctrl+Shift+P -> Run Task -> "Make: clean !!1" - удаляет файлы типа *.o и *.exe

// А кнопка RUN запустит тот таск, который помечен как "isDefault":true в "group" в tasks.json


