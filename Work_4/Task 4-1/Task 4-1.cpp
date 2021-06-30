#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;

/**
 * \brief Заполнение массива с клавиатуры
 * \param array Массив
 * \param size Размер массива
 */
void inputValue(int* array, const int size);

/**
 * \brief Заполнение массива случайными числами
 * \param array Массив
 * \param size Размер массива
 * \param right_bound Минимальная граница
 * \param left_bound Максимальная граница
 */
void Random(int* array, const int size, const int right_bound, const int left_bound);

/**
 * \brief Вывод массива
 * \param array Массив
 * \param size Размер массива
 */
void Print(int* array, const int size);

/**
 * \brief Проверка индекса элемента на четность
 * \param i Индекс массива
 */
bool Even(const int i);

/**
 * \brief Уничтожает массив
 * \param array Массив
 */
void Destroy(int* array);

/**
* \brief Находит сумму четных элементов масива
* \param array Массив
* \param size Размер масива
* \\return Возвращает сумму чётных элементов масива
*/
int Sum(int* array, const int size);

/**
* \brief Находит количество элементов массива, значения которых состоят из двух цифр.
* \param array Массив
* \param size Размер масива
* \\return Возвращает количество элементов массива, значения которых состоят из двух цифр.
*/
int Element(int* array, const int size);

/**
* \brief Заменяет последний отрицательный элемент масива на модуль первого элемента массива.
* \param array Массив
* \param size Размер масива
* \\return Возвращает последний отрицательный элемент массива на модуль первого элемента массива.
*/
int lastNegativeElemen(int* array, const int size);

enum class Value {
    NONE,
    KEYBOARD,
    RANDOM,
};

int main() {
    setlocale(0, "");

    const auto right_bound = -1000;
    const auto left_bound = 1000;

    int size;
    cout << "Введите размер массива\n";
    cin >> size;

    int* array;
    array = new int[size];

    int choice;
    cout << "Введите как заполнять массив, 1-ввод с клавиатуры, 2-рандомные числа\n";
    cin >> choice;

    const auto value = static_cast<Value>(choice);
    switch (value) {
    case Value::KEYBOARD:
        inputValue(array, size);
        Print(array, size);
        break;
    case Value::RANDOM:
        Random(array, size, right_bound, left_bound);
        Print(array, size);
        break;
    default:
        cout << "Ввели не корректное значение!!!!'\n'";

    }

    cout <<"Сумма четных элементов: " <<Sum(array, size) << endl;
    cout <<"Количество элементов массива, значения которых состоят из двух цифр: " <<Element(array, size) << endl;
    cout <<"Заменить последний отрицательный элемент массива на модуль первого элемента массива: " <<lastNegativeElemen(array, size) << endl;
    system("pause");
    Destroy(array);
    return 0;
}


void inputValue(int* array, const int size) {
    for (size_t i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void Random(int* array, const int size, const int right_bound, const int left_bound) {
    for (size_t i = 0; i < size; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());

        const uniform_int_distribution<> uniformIntDistribution(right_bound, left_bound);
        for (size_t i = 0; i < size; i++) {
            array[i] = uniformIntDistribution(gen);
        }
    }
}

void Print(int* array, const int size) {
    cout << "Массив [" << size << "]" << "= {";
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << "; " << setw(3);
    }
    cout << array[size - 1] << "}" << endl;
}

void Destroy(int* array) {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }
}

bool Even(const int a) {
    return a % 2 == 0;
}


int Sum(int* array, const int size) {
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        if (Even(array[i]))
            sum += array[i];
    }
    return sum;
}

int Element(int* array, const int size) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (abs(array[i]) >= 10 && abs(array[i]) <= 99)
            count++;
    }
    return count;
}

int lastNegativeElemen(int* array, const int size) {
    int min_i = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] < 0)
            min_i = i;
    }
    array[min_i] = abs(array[0]);
    return array[min_i];
}
