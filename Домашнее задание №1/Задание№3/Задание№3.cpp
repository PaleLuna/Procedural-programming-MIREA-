﻿#include <iostream>
#include <cstdlib>

using namespace std;

double GetCoeff(char nameCoeff)
{
	double userInput;

	while (true)
	{

		cin >> userInput;

		//Очистка буфера от лишних символов
		cin.ignore(256, '\n');

		//Проверка на корректность введенных данных
		if (cin.fail())
		{
			cout << endl << "Неверный формат ввода" << endl;
			cout << "Введите переменную '" << nameCoeff << "' повторно: ";

			//сброс аварийного состояния 'cin' 
			cin.clear();

			//очистка буфера прошлого ввода
			cin.ignore(256, '\n');

			continue;
		}

		else if (nameCoeff == 'b' && userInput == 0)
		{
			cout << endl << "Переменная 'b' не может равняться нулю!" << endl;
			cout << "Повторно переменную 'b': ";

			continue;
		}


		else
			break;
	}

	return userInput;
}

int main()
{
	system("chcp 1251>nul");

	int b, c;
	double x;
	
	cout << "Решение уравнения вида bx + c = 0" << endl << endl;

	cout << "Введите переменную 'b': ";
	b = GetCoeff('b');
	cout << endl << "Введите переменную 'c': ";
	c = GetCoeff('c');
	cout << endl;

	//Решение уравнения
	x = (double)-c / b;
	cout << "x = " << x << endl;

	system("pause>nul");
	return 0;

}