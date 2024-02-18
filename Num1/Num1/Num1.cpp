#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	time_t  current_time = time(NULL);
	srand(current_time);

	
	const int array_size = 15;
	int rand_integers[array_size], *pointer;
	int ans = 0, end_of_range = 100;
	
	pointer = rand_integers;

	cout << "\nИсходный массив:\n";
	for (int i = 0; i < array_size; i++) {
		*pointer = rand() % end_of_range;
		cout << *pointer << " ";
		pointer++;
	}
	cout << "\n\n";

	pointer = rand_integers;


	cout << "Числа,кратные 8 в диапазоне 2-20:\n";
	for (int i = 0; i < array_size; i++) {
		if (*pointer > 2 && *pointer < 20 && *pointer % 8 == 0) {
			cout << *pointer << " ";
			ans += 1;
		}
		pointer++;
	}
	cout << "\n\nКоличество чисел:\n" << ans << endl;
}