#include <iostream>
#include <cmath>
#include "Rational.h"

using namespace std;

Rational y(double);

int main()
{
	setlocale(LC_ALL, "RUS");
	
	Rational n(3, 2);
	Rational b2(3, 2);

	cout << n << endl;
	cout << b2 << endl;
	cout << n * b2 << endl;

	cout << y(1.3) << endl;

	system("pause");
}

Rational y(double x)
{
	return Rational(2 * x, 1) * Rational(1.3, x);
}
