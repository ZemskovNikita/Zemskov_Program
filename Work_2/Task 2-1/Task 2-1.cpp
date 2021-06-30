#include <iostream>
#include <string>
#include <clocale>

using namespace std;


/**
* \brief Перечисляемый тип вычеслений, для которых считаем сумму, разность, произведение, частное.
*/
enum class Result {


	/**
	* \brief Неправильно выбор.
	*/
	none,


	/**
	* \brief расчет --- сумма чисел.
	*/
	sum,


	/**
	* \brief расчет --- разности чисел.
	*/
	difference,


	/**
	* \brief расчет --- произведения чисел.
	*/
	product,


	/**
	* \brief расчет --- частного чисел.
	*/
	quotient,
};

/**
 * \brief Функция расчета суммы чисел.
 * \param число "a".
 * \return сумма.
 */
double GetSumOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета разности чисел.
 * \param число "a".
 * \return разность.
 */
double GetDifferenceOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета произведения чисел.
 * \param число "a".
 * \return произведение.
 */
double GetProductOfNumbers(const double a, const double b);

/**
 * \brief Функция расчета частного чисел.
 * \param число "a".
 * \return частное
 */
double GetQuotientOfNumbers(const double a, const double b);

/**
 * \brief Ввод самого числа.
 * \param message Разъясняющая надпись.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return численное значение.
 */
double WriteaANumber(const string& message = "", ostream& out = cout, istream& in = cin);

/**
 * \brief
 * \param message Сообщение для пользователя.
 * \param out Произвольный поток вывода.
 * \param in Произвольный поток ввода.
 * \return то что выбрал пользователь.
 */
Result ReadUserChoice(const string& message = "", ostream& out = cout, istream& in = cin);


int main() {
	setlocale(LC_ALL, "Russian");

	const auto message = "Выберите что посчитать: "
		+ to_string(static_cast<int>(Result::sum)) + " - сумма,"
		+ to_string(static_cast<int>(Result::difference)) + " - разность,"
		+ to_string(static_cast<int>(Result::product)) + " - произведнение,"
		+ to_string(static_cast<int>(Result::quotient)) + " - частное\n";

	const auto result = ReadUserChoice(message);

	switch (result) {
	case Result::sum: {
		const auto number_1 = WriteaANumber("Введите число = ");
		const auto number_2 = WriteaANumber("Введите число = ");

		const auto Sum = GetSumOfNumbers(number_1, number_2);
		cout << "\nСумма " << Sum << endl;
		break;
	}
	case Result::difference: {
		const auto number_1 = WriteaANumber("Введите число = ");
		const auto number_2 = WriteaANumber("Введите число = ");
		
		const auto difference = GetDifferenceOfNumbers(number_1, number_2);
		cout << "\nРасзность " << difference << endl;
		break;
	}
	case Result::product: {
		const auto number_1 = WriteaANumber("Введите число = ");
		const auto number_2 = WriteaANumber("Введите число = ");
		
		const auto product = GetProductOfNumbers(number_1, number_2);
		cout << "\nПроизведение " << product << endl;
		break;
	}
	case Result::quotient: {
		const auto number_1 = WriteaANumber("Введите число = ");
		const auto number_2 = WriteaANumber("Введите число = ");
		
		auto quotient = GetQuotientOfNumbers(number_1, number_2);
		cout << "\nЧастное " << quotient << endl;
		break;
	}
	default:
		cout << "ошибка!";
	}
	system("pause");
	return 0;
}

double GetSumOfNumbers(const double a, const double b) {
	return a + b;
}

double GetDifferenceOfNumbers(const double a, const double b) {
	return a - b;
}

double GetProductOfNumbers(const double a, const double b) {
	return a * b;
}
double GetQuotientOfNumbers(const double a, const double b) {
	return a / b;
}

double WriteaANumber(const string& message, ostream& out, istream& in) {
	out << message;
	double number;
	in >> number;
	return number;
}

Result ReadUserChoice(const string& message, ostream& out, istream& in) {
	out << message;
	int userInput;
	in >> userInput;
	return static_cast<Result>(userInput);
}