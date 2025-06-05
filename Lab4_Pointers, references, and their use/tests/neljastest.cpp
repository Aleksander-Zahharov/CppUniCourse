/**
 * @file neljastest.cpp
 * @brief Тестовый файл для проверки функциональности различных задач.
 * 
 * Этот файл содержит тесты для:
 * - Задачи 1: Обмен значений двух переменных с использованием ссылок и указателей.
 * - Задачи 2: Решение квадратного уравнения.
 * - Задачи 3: Функциональность класса DynamicLine (закомментировано).
 * - Задачи 4: Функциональность класса MyArray (закомментировано).
 */

 #include <cstdlib>
 #include <iostream>
 #include <cmath>
 #include "neljas.h"
 using namespace std;
 
 int testcount = 0;
 
 /**
	* @brief Макрос для тестирования двух значений типа double с ожидаемыми результатами.
	* 
	* @param a Описание теста.
	* @param b Первое фактическое значение.
	* @param b2 Ожидаемое значение для первой переменной.
	* @param c Второе фактическое значение.
	* @param c2 Ожидаемое значение для второй переменной.
	*/
 #define TEST(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " << (cmpf(b,b2) && cmpf(c,c2) ? "OK" :"FAIL") << endl
 
 /**
	* @brief Макрос для тестирования двух решений с ожидаемыми результатами.
	* 
	* @param a Описание теста.
	* @param b Первое фактическое решение.
	* @param b2 Ожидаемое решение для первой переменной.
	* @param c Второе фактическое решение.
	* @param c2 Ожидаемое решение для второй переменной.
	*/
 #define TEST2(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " << (cmpresult(b,c,b2,c2) ? "OK" :"FAIL") << endl

 /**
 * @brief Макрос для тестирования функциональности DynamicLine.
 * 
 * @param a Описание теста.
 * @param b Первая конечная точка линии.
 * @param b2 Ожидаемые координаты первой конечной точки.
 * @param c Вторая конечная точка линии.
 * @param c2 Ожидаемые координаты второй конечной точки.
 */
#define TEST3(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " \
<< ((cmpf((b)->x, (b2)->x) && cmpf((b)->y, (b2)->y) && cmpf((c)->x, (c2)->x) && cmpf((c)->y, (c2)->y)) ? "OK" : "FAIL") << endl

/**
 * @brief Макрос для тестирования функциональности MyArray.
 * 
 * @param a Описание теста.
 * @param b Фактический размер массива.
 * @param b2 Ожидаемый размер массива.
 * @param c Фактический элемент на индексе 0.
 * @param c2 Ожидаемый элемент на индексе 0.
 */
#define TEST4(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " \
		<< ((b == b2 && c == c2) ? "OK" : "FAIL") << endl
 
 /**
	* @brief Сравнивает два значения типа double с точностью до 0.001.
	* 
	* @param a Первое значение.
	* @param b Второе значение.
	* @return true, если значения примерно равны, иначе false.
	*/
 bool cmpf (double a, double b) {
	 if (fabs (a - b) < 0.001f) 
		 return true;
	 return false;
 }
 
 /**
	* @brief Сравнивает две пары решений на эквивалентность.
	* 
	* @param s1 Первое решение первой пары.
	* @param s2 Второе решение первой пары.
	* @param r1 Первое решение второй пары.
	* @param r2 Второе решение второй пары.
	* @return true, если пары эквивалентны, иначе false.
	*/
 bool cmpresult (double s1, double s2, double r1, double r2) {
	 return (cmpf (s1, r1) && cmpf (s2, r2)) || (cmpf (s1, r2) && cmpf (s2, r1));
 }
 
 /**
	* @brief Основная функция для запуска всех тестов.
	* 
	* @param argc Количество аргументов командной строки.
	* @param argv Массив аргументов командной строки.
	* @return EXIT_SUCCESS, если все тесты прошли успешно.
	*/
int main (int argc, char* argv[]) {

	// Задача 1: обмен значений
	cout << "\n--Задача 1. Обмен значений двух переменных с использованием ссылки и указателя" << endl;
	double x = 1.0, y = -2.0;
	swap_ref<double> (x, y);
	TEST("swap_ref<double> (x, y)(-2,1)", x, -2.0, y, 1.0);
	swap_ptr<double> (&x, &y);
	TEST("swap_ptr<double> (&x, &y)(1,-2)", x, 1.0, y, -2.0);

	// Задача 2: решение уравнения
	cout << "\n--Задача 2. Функция для решения уравнения" << endl;
	double a = 1.0, b = -2.0, c = 1.0;
	double solution1 = 0, solution2 = 0;	// решения должны быть 1 и 1
	if (solve (a, b, c, solution1, solution2)) {
		cout << "Решения: " << solution1 << ", " << solution2 << endl;
	} else {
		cout << "Нет действительных решений!" << endl;	
	}
	TEST2("solve (1, -2, 1, s1, s2)(1,1)", solution1, 1, solution2, 1);

	// Задача 3
	cout << "\n--Задача 3." << endl;
	Point2 p1 {1.0, 2.0}; 
	Point2 p2 {0,0}; 
	Point2 p3 {5.0, 2.0};

	DynamicLine<Point2> l1 {&p1, &p2};	// линия между p1 и p2
	DynamicLine<Point2> l2 {nullptr, nullptr};
	l2 = l1;					// копируем линию l1 (конечные точки остаются теми же)
	l2.p2 = &p3;				// задаем вторую конечную точку для l2
	p1.x = 2.0;	
	
	TEST3("DynamicLine copy and endpoint modification", l1.p1, &p1, l1.p2, &p2);
	TEST3("DynamicLine endpoint reassignment", l2.p1, &p1, l2.p2, &p3);

	// Задача 4
	cout << "\n--Задача 4. Функциональность MyArray" << endl;
	MyArray<int> numbers;			// массив чисел
	numbers.addElement (5);			// добавляем один элемент
	numbers.addElement (11);		// и еще один
	MyArray<int> copy = numbers;	// копируем массив (конструктор копирования)
	copy.addElement (13);			// добавляем элемент в копию
	
	MyArray<int> copy2;
	copy2 = numbers;				// используем оператор присваивания
	
	if (numbers.getSize () != 2 || copy.getSize () != 3 || copy2.getSize () != 2)	// проверяем размеры 
		cout << "Копирование не удалось – неверные размеры!" << endl;
	if (numbers.elementAt(0) != copy.elementAt(0) || numbers.elementAt(1) != copy.elementAt(1)) // проверяем содержимое
		cout << "Копирование не удалось – неверные элементы!" << endl;

	TEST4("MyArray size and content check", numbers.getSize(), 2, numbers.elementAt(0), 5);
	TEST4("MyArray copy size and content check", copy.getSize(), 3, copy.elementAt(2), 13);
		
	try {
		numbers.elementAt(10); // Доступ к недопустимому индексу
		cout << "Test 4.3: Out of range access: FAIL" << endl;
	} catch (const std::out_of_range&) {
		cout << "Test 4.3: Out of range access: OK" << endl;
	}
		
	cout << "\nКоличество тестов: " << testcount << endl;
	return EXIT_SUCCESS;
}

// "make test" запускает этоти тесты
