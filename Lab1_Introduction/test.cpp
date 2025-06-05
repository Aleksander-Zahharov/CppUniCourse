/* See on testimise peaprogramm. Töö algab funktsioonis 'main'. */
#include <iostream> /* Sisend ja väljund */
#include <cstdlib>  /* EXIT_SUCCESS jt konstandid */
#include "functions.h" /* Meie oma funktsioonid */

using namespace std; /* Nimeruumi valik (selgitatakse praktikumis) */

int testcount = 0;
#define TEST(ex) cout << "Test " << ++testcount << ": " << #ex << " " << ((ex) ? "OK" :"FAIL") << endl

int main() {
    // Kas funktsioon minimum on defineeritud? (теперь да)
    // TODO: Lisa oma testid (добавил)
    cout << "--Testid funktsiooni minimum" << endl;
    TEST(minimum(35, 40) == 35);
    TEST(minimum(35, 40) != 40);
    TEST(minimum(50, 1) == 1);
    TEST(minimum(50, 1) != 50);
    TEST(minimum(1000, 10) == 10);
    TEST(minimum(10, 1000) == 10);

    cout << "--Testid funktsiooni maximum" << endl;
    TEST(maximum(35, 40) == 40);
    TEST(maximum(50, 1) == 50);
    TEST(maximum(1000, 10) == 1000);
    TEST(maximum(10, 1000) == 1000);

    cout << "--Testid funktsiooni product" << endl;
    TEST(product(35, 40) == 1400);
    TEST(product(50, 1) == 50);
    TEST(product(1000, 10) == 10000);
    TEST(product(10, 1000) == 10000);

    cout << "--Testid funktsiooni power" << endl;
    TEST(power(2, 3) == 8);
    TEST(power(5, 0) == 1);
    TEST(power(10, 2) == 100);
    TEST(power(2, -1) == 0);
    TEST(power(0, -1) == 0); // Check for division by zero

    cout << "--Testid funktsiooni gcd" << endl;
    TEST(gcd(35, 40) == 5);
    TEST(gcd(50, 1) == 1);
    TEST(gcd(1000, 10) == 10);
    TEST(gcd(10, 1000) == 10);

    cout << "Testide arv: " << testcount << endl; 
    return EXIT_SUCCESS;
}