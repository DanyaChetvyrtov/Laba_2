#include <iostream>
#include <string>
using namespace std;


bool isInteger(string test_string) {
    char *pointer = &test_string[0];

    for (int i = 0; i < test_string.size(); i++) {
        if (isdigit(*pointer) == 0)
            return false;
        pointer++;
    }
    return true;
}

int getNaturalInteger() {
    string user_string;
    int array_size;


    while (true) {
        try {
            cin >> user_string;


            if (isInteger(user_string) != true) {
                throw "error";
            }

            array_size = stoi(user_string);

            return array_size;
        }
        catch (...) {
            cout << "Ошибка ввода! Нужно ввести натуральное число (N)." << endl;

            cin.clear();
            while (cin.get() != '\n');

            continue;
        }
    }
}

int inRange(int range_top){
    int valid_range;

    do {
        valid_range = getNaturalInteger();
        if (0 >= valid_range || valid_range > range_top) {
            cout << "Число должно быть от 1 до " << range_top << ".\n";
            continue;
        }
        return valid_range;
    } while (true);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    time_t  current_time = time(NULL);
    srand(current_time);

    int user_size, range_start, range_end;


    cout << "Введите размер массива: ";
    user_size = getNaturalInteger();

    cout << "Начиная с какого числа выводить?\n";
    range_start = inRange(user_size) - 1;

    cout << "По какое?\n";
    range_end = inRange(user_size) - 1;

    // При необходимости корректируем начало и конец диапазона
    if (range_start > range_end) {
        int gap;

        cout << "Начальный номер не можнет быть больше конечного.\n";
        gap = range_start;
        range_start = range_end;
        range_end = gap;
        cout << "Диапазон был отредактирован.\n";
    }

    // Создаём динамический массив
    int* array = new int[user_size];


    cout << "\nИсходный массив:\n";
    for (int i = 0; i < user_size; i++) {
        *(array + i) = rand() % 100;
        cout << *(array + i) << " ";
    }


    //////////// Вывод чисел диапазона пользователя ////////////
    cout << "\n\nВывод чисел с " << range_start + 1 << " по " << range_end + 1 << " номер:\n";
    for (int i = range_start; i <= range_end; i++) {
        cout << *(array + i) << " ";
    }

    cout << "\nВсего в этом диапазоне " << range_end - range_start + 1 << " чисел.";
    ////////////////////////////////////////////////////////////
    

    ////// Сумма чисел, находящихся после максимального //////
    int max_el = 0, max_el_index = 0, sum = 0;


    // Поиск максимального элемента
    for (int i = 0; i < user_size; i++) {
        if (*(array + i) > max_el) {
            max_el = *(array + i);
            max_el_index = i;
        }
    }

    cout << "\n\nМаксимальное числовое значение в массиве -> " << max_el << endl;

    // Сумма элементов после максимального 
    for (int i = max_el_index + 1; i < user_size; i++) {
        sum += *(array + i);
    }
    cout << "Сумма элементов после наибольшего числа -> " << sum << endl;
    ////////////////////////////////////////////////////////////


    //////////////////////// Сортировка ////////////////////////
    int gap;


    for (int i = 0; i < user_size; i++) {
        for (int j = i+1; j < user_size ; j++) {
            if (*(array + i) < *(array + j)) {
                gap = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = gap;
            }
        }
    }

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < user_size; i++)
        cout << *(array + i) << " ";

    cout << endl;
    ////////////////////////////////////////////////////////////
  
    delete[] array;
    array = NULL;
}