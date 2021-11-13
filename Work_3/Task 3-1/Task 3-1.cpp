#include<iostream>
#include<cmath>

using namespace std;


/**
 * \brief функция для расчета заначений табуляции.
 * \x начало интервала.
 * \return значение табуляции.
*/
double Tabulation(const double x);


/**
 * \brief Вход в программу.
 * \return в случае успеха, возвращает 0.
*/
int main() {
	setlocale(0, "");
	double x = 1.0;
	const auto z = 3;
	const auto step = 0.2;
	double eps = 0.00000001;

	for (x; x <= z + eps; x += step) {
		if (x > 0)
		cout << "x: " << x << " y: " << Tabulation(x) << endl;
		else
			cout << "в точке x = " << x << " невозможно найти значение функции" << endl;
	}

	system("pause");
	return 0;
}

double Tabulation(double x) {
	return sin(log(x)) - cos(log(x)) + 2 * log(x);
}

