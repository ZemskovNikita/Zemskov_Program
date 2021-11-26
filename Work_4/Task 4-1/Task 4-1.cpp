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
bool IsEven(const int i);

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
void lastNegativeElemen(int* array, const int size);



enum class Value {
    NONE,
    KEYBOARD,
    RANDOM,
};

int main() {
    setlocale(0, "");

    const auto right_bound = -1000;
    const auto left_bound = 1000;

    int size_t;
    cout << "Введите размер массива\n";
    cin >> size_t;

    int* array;
    array = new int[size_t];

    int choice;
    cout << "Введите как заполнять массив, 1-ввод с клавиатуры, 2-рандомные числа\n";
    cin >> choice;

    const auto value = static_cast<Value>(choice);
    switch (value) {
    case Value::KEYBOARD:
        inputValue(array, size_t);
        Print(array, size_t);
        break;
    case Value::RANDOM:
        Random(array, size_t, right_bound, left_bound);
        Print(array, size_t);
        break;
    default:
        cout << "Ввели не корректное значение!!!!'\n'";

    }

    cout <<"Сумма четных элементов: " <<Sum(array, size_t) << endl;
    cout <<"Количество элементов массива, значения которых состоят из двух цифр: " <<Element(array, size_t) << endl;
    cout <<"Заменить последний отрицательный элемент массива на модуль первого элемента массива: " << endl;
    lastNegativeElemen(array, size_t);
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
        cout << array[i] << " " << setw(3);
    }
    cout << "}" << endl;
}

void Destroy(int* array) {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }
}

bool IsEven(const int i) {
    return i % 2 == 0;
}


int Sum(int* array, const int size) {
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        if (IsEven(array[i]))
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

void lastNegativeElemen(int* array, const int size) {
    int a = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (array[i] < 0 && a == 0){
            a++;
            array[i] = abs(array[0]);
        }
    }
    Print(array, size);
}