#include <iostream>

using namespace std;

float GetCoeff(char nameCoeff)
{
	float userInput;

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

		else
			break;
	}

	return userInput;
}

int main()
{
	system("chcp 1251>nul");

	float b, c, x;

	cout << "Решение уравнения вида bx + c = 0" << endl << endl;

	cout << "Введите переменную 'b': ";
	b = GetCoeff('b');
	cout << endl << "Введите переменную 'c': ";
	c = GetCoeff('c');
	cout << endl;

	if (b == 0 && c == 0)
	{
		cout << "X - любое число";
	}

	else if (b == 0)
	{
		cout << "Решений нет";
	}

	else
	{
		//Решение уравнения
		x = -c / b;
		cout << "x = " << x << endl;
	}

	system("pause>nul");
	return 0;

}