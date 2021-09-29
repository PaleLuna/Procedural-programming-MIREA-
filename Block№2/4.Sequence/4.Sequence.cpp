#include <iostream>
#include <typeinfo>
#include <cstdlib>

using namespace std;

//Считываение ввода пользователя и проверка на корректность
int UserInput()
{
	int userInput;

	while (true)
	{
		cin >> userInput;
		cin.ignore(32767, '\n');

		if (cin.fail())
		{
			cout << "Ошибка формата. Введите целочисленное число N: ";

			cin.clear();
			cin.ignore(32767, '\n');

			continue;
		}
		else
		{
			break;
		}
	}

	return userInput;
}

//Вывод 10 последовательных натуральных чисел
void GetLine(int n)
{
	for (int i = 0; i <= 10; i++)
	{
		printf("%i ", n + i);
	}
}

int main()
{
	system("chcp 1251>nul");

	printf("**********ПОСЛЕДОВАТЕЛЬНОСТЬ ЧИСЕЛ**********\n\n");

	int n;

	printf("Введите целое число 'N': ");
	n = UserInput();

	GetLine(n);

	system("pause>nul");
	return 0;
}