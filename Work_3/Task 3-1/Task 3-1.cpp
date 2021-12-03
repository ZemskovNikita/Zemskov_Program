#include<iostream>
#include<cmath>

using namespace std;


/**
 * \brief функция для расчета значений табуляции.
 * \x начало интервала.
 * \return значение табуляции.
*/
double Tabulation(const double x);

/**
 * \brief функция для расчета значений табуляции.
 * \x начало интервала.
 * \z конец интервала.
 * \eps эпислент.
 * \step шаг.
*/
void Сalculation(double x, const int z, const double eps, const double step);


/**
 * \brief Вход в программу.
 * \return в случае успеха, возвращает 0.
*/
int main() {
	setlocale(0, "");
	double x = 1.0;
	const int z = 3;
	const double step = 0.2;
	double eps = 0.00000001;

	Сalculation(x, z, eps, step);

	system("pause");
	return 0;
}

double Tabulation(double x) {
	return sin(log(x)) - cos(log(x)) + 2 * log(x);
}

void Сalculation(double x, const int z, const double eps, const double step) {
	for (x; x <= z + eps; x += step) {
		if (x > 0)
			cout << "x: " << x << " y: " << Tabulation(x) << endl;
		else
			cout << "в точке x = " << x << " невозможно найти значение функции" << endl;
	}
}