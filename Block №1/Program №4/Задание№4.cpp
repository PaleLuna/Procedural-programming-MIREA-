#include <iostream>
#include <cstdlib>
#include <cmath>

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
			cout << "Введите коэффициент '" << nameCoeff << "' повторно: ";

			//сброс аварийного состояния 'cin' 
			cin.clear();

			//очистка буфера прошлого ввода
			cin.ignore(256, '\n');

			continue;
		}

		else if (nameCoeff == 'a' && userInput == 0)
		{
			cout << endl << "Старший коэффициент не должен равняться нулю!" << endl;
			cout << "Повторно введите старший коэффициент 'a': ";

			continue;
		}


		else
			break;
	}

	return userInput;
}

double FindD(double a, double b, double c)
{
	double d = pow(b, 2) - (4 * a * c);
	cout << d << endl;

	return d;
}

int main()
{
	system("chcp 1251>nul");

	double a, b, c; //коэффициенты, введенные пользователем
	double d; //Дискриминант
	double x1, x2; //корни уравнения

	cout << "Решение квадратного уравнения" << endl << endl;

	cout << "Введите старший коэффициент a: ";
	a = GetCoeff('a');
	cout << endl << "Введите средний коэффициент 'b': ";
	b = GetCoeff('b');
	cout << endl << "Введите свободный член 'c': ";
	c = GetCoeff('c');
	cout << endl;

	d = FindD(a, b, c);

	if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);

		cout << "x1 = " << x1 << endl << "x2 = " << x2;

	}
	else if (d == 0)
	{
		x1 = (-b - sqrt(d)) / 2 * a;

		cout << "x1 = " << x1;
	}

	else
	{
		cout << "Решений нет";
	}



	system("pause>nul");
	return 0;
}
