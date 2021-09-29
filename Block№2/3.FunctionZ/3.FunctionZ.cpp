#include <iostream>
#include <cmath>

using namespace std;

//Проверка на корректность ввода
double GetVar(char nameVar)
{
	double userInput;

	while (true)
	{
		cin >> userInput;
		cin.ignore(32767, '\n');


		if (cin.fail())
		{
			cout << "Произошла ошибка! Введите переменную '" << nameVar << "' повторно: ";

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

//Вычисление функции
double GetResult(double x, double y, double b)
{
	if ((b - x) < 0 || (b - y) < 0)
	{
		return NAN;
	}
	else
	{
		double result = log(b - y) * sqrt(b - x);

		return result;
	}

}


int main()
{
	system("chcp 1251>nul");

	double x, y, b;
	double z;

	printf("Вычисление функции: z = ln(b - y) * sqrt(b - x)\n\n");


	printf("Введите переменную 'x': ");
	x = GetVar('x');
	printf("Введите переменную 'y': ");
	y = GetVar('y');
	printf("Введите переменную 'b': ");
	b = GetVar('b');

	z = GetResult(x, y, b);

	if (isnan(z))
	{
		printf("Решений нет\n");
	}
	else
	{
		printf("Результатом функции является: %.2f", z);
	}

	system("pause>nul");
	return 0;
}