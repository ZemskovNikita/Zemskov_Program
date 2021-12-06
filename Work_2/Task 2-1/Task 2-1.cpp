#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;

/**
* \brief Выбор пользователя, будем считать сумму, разность, произведение или частное.
*/
enum class Choice {


	/**
	* \brief Неправильный выбор.
	*/
	none,


	/**
	* \brief расчет суммы чисел.
	*/
	sum,


	/**
	* \brief расчет разности чисел.
	*/
	difference,


	/**
	* \brief расчет произведения чисел.
	*/
	multiplication,


	/**
	* \brief расчет частного чисел.
	*/
	division,
};

/**
 * \brief Функция расчета суммы чисел.
 * \param число "a".
 * \param число "b".
 */
void GetSumOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета разности чисел.
 * \param число "a".
 * \param число "b".
 */
void GetDifferenceOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета произведения чисел.
 * \param число "a".
 * \param число "b".
 */
void GetMultiplicationOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета частного чисел.
 * \param число "a".
 * \param число "b".
 */
void GetDivisionOfNumbers(const double a, const double b);

/**
 * \brief Ввод первого числа.
 */
double WriteaFirstNumber();

/**
 * \brief Ввод второго числа.
 */
double WriteaSecondNumber();


int main() {
	setlocale(LC_ALL, "Russian");

	const double a = WriteaFirstNumber();
	const double b = WriteaSecondNumber();


	cout << " Цифра 1 -- Вычисляет сумму " << endl;
	cout << " Цифра 2 -- Вычисляет разность" << endl;
	cout << " Цифра 3 -- Вычисляет произведение" << endl;
	cout << " Цифра 4 -- Вычисляет частное" << endl;

	int count = 0;
	cin >> count;
	const auto value = static_cast<Choice>(count);
	switch (value) {
	case Choice::sum:
		GetSumOfNumbers(a, b);
		break;
	case Choice::difference:
		GetDifferenceOfNumbers(a, b);
		break;
	case Choice::multiplication:
		GetMultiplicationOfNumbers(a, b);
		break;
	case Choice::division:
		GetDivisionOfNumbers(a, b);
		break;
	default:
		break;
	}
}


void GetSumOfNumbers(const double a, const double b) {
	cout << a << " + " << b << " = " << a + b;
}

void GetDifferenceOfNumbers(const double a, const double b) {
	cout << a << " - " << b << " = " << a - b;
}

void GetMultiplicationOfNumbers(const double a, const double b) {
	cout << a << " * " << b << " = " << a * b;
}
void GetDivisionOfNumbers(const double a, const double b) {
	cout << a << " / " << b << " = " << a / b;
}

double WriteaFirstNumber() {
	double value;
	cout << "Введите первое число: ";
	cin >> value;
	return value;
}

double WriteaSecondNumber() {
	double value;
	cout << "Введите второе число: ";
	cin >> value;
	return value;
}