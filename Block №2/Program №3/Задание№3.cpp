﻿#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

//Проверка на корректность ввода
double GetVar(char nameVar, double x)
{
	double userInput;

	while(true)
	{
		cin >> userInput;
		cin.ignore(32767, '\n');


		if (cin.fail())
		{
			cout << "Произошла ошибка! Введите переменную '" << nameVar <<"' повторно: ";

			cin.clear();
			cin.ignore(32767, '\n');

			continue;
		}
		else if (nameVar = 'b' && userInput < x)
		{
			cout << "Ошибка! Переменная 'b' не может быть меньше переменной 'x'. Повторите попытку: ";

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
	double result = sqrt(b - x);

	return result;
}


int main()
{
	system("chcp 1251>nul");

	double x, y, b;
	double z;

	cout << "Вычисление функции: z = ln(b - y) * sqrt(b - x)" << endl << endl;

	
	cout << "Введите переменную 'x': ";
	x = GetVar('x', 0);
	cout <<endl << "Введите переменную 'y': ";
	y = GetVar('y', 0);
	cout <<endl << "Введите переменную 'b': ";
	b = GetVar('b', x);

	z = GetResult(x, y, b);

	cout << endl << "Результатом функции является: " << z;

	system("pause>nul");
	return 0;
}