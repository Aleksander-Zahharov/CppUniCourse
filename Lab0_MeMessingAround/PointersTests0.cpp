#include <iostream>
#include <windows.h>

using namespace std; // Теперь можно использовать cout и endl без std::

int main() {
    SetConsoleOutputCP(CP_UTF8); // Позволяет отображать русские символы в консоли. Для стандартного HelloWorld она не нужна
	cout << "\n лол \t 3" << endl << endl;

	cout << "Pointers / Указатели" << endl;
    int a = 5;
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;

	int* b = &a; // Указатель на адрес переменной а
	cout << "Адрес b = " << b << endl; // b хранит адрес переменной а
	cout << "Значение *b = " << *b << endl << endl;

	*b = 100; // Значение переменной а теперь 10
	cout << "a = " << a << endl;
	cout << "*b = " << *b << endl;
	a=88;	// А теперь 88
	cout << "a = " << a << endl;
	cout << "*b = " << *b << endl << endl;
	// Изменение данных связанных переменной и указателя работает в обе стороны, тк у них общая ячейка памяти

	cout << "References / Ссылки" << endl;
	int c = 5, d = 9;                       		// define variables c and d
	int& refToC = c;                        		// refToC is new name to variable c
	cout << c << "," << refToC << "," << d << endl; // returns 5,5,9
	c = 7;                                  		// change c value
	cout << c << "," << refToC << "," << d << endl; // returns 7,7,9
	refToC = 11;                            		// change refToC value
	cout << c << "," << refToC << "," << d << endl << endl; // returns 11,11,9
	// Изменения значений также работают в обе стороны 
	
	
	// Референсам можно присваивать, только ОБЫЧНЫЕ переменные.
	// Следующие строки вызовут ошибку компиляции
	// int& refToNowhere = 99;
	// int& refToNowhere = &a;
	// int& refToNowhere = b;

	// Оператор new вычисляет, сколько памяти необходимо для данного объекта,
	// выделяет ее и возвращает указатель на начало слота памяти:
	int* e = new int; 
	//Значения, созданные с помощью ключевого слова new, должны быть освобождены с помощью delete.
	// NB! В случае выделения памяти для нескольких объектов с помощью оператора new[], для освобождения необходимо использовать delete[].
	delete e;

	// Если указатель на объект, то -> используется для доступа к его данным или методам

	

	return EXIT_SUCCESS; // Все равно что return 0;
}

// Ctrl+Shift+P -> Run Task -> "Обычный таск: Скомпилировать и запустить PointersTests0 (без Makefile)"
// Ctrl+Shift+P -> Run Task -> "Make: clean !!1" - удаляет файлы типа *.o и *.exe
