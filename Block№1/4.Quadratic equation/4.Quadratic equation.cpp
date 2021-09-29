#include <iostream>
#include <cmath>

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
			cout << "Введите коэффициент '" << nameCoeff << "' повторно: ";

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

float LinearEquation(float b, float c)
{
	cout << "Так как, а = 0, решим линейное уравнение типа bx + c = 0\n";

	float x = -c / b;

	return x;
}

void FindX(double a, double b, double c)
{
	double d = pow(b, 2) - (4 * a * c);

	if (d > 0)
	{
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);

		printf("X1 = %.2f\nX2 = %.2f\n", x1, x2);
	}

	else if (d == 0)
	{
		double x1 = (-b + sqrt(d)) / (2 * a);
		printf("X1 = %.2f\n", x1);
	}

	else
		cout << "Решений нет\n";
}

int main()
{
	system("chcp 1251>nul");

	float a, b, c; //коэффициенты, введенные пользователем

	cout << "Решение квадратного уравнения" << endl << endl;

	cout << "Введите старший коэффициент a: ";
	a = GetCoeff('a');
	cout << endl << "Введите средний коэффициент 'b': ";
	b = GetCoeff('b');
	cout << endl << "Введите свободный член 'c': ";
	c = GetCoeff('c');
	cout << endl;

	if (a == 0 && b == 0 && c == 0)
	{
		cout << "X - любое число ";
	}
	else if (a == 0 && b == 0)
	{
		cout << "Решений нет\n";
	}

	else if (a == 0)
	{
		printf("X = %.2f\n", LinearEquation(b, c));
	}

	else
	{
		FindX(a, b, c);
	}

	system("pause>nul");
	return 0;
}
