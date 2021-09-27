#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

const double pi = 3.14;

//Пользовательский ввод
double GetVar(string nameVar)
{
	double userInput;

	while (true)
	{
		cin >> userInput;
		cin.ignore(256, '\n');

		//Проверка на корректность ввода
		if (cin.fail())
		{
			cout << endl << "Неверный формат вводимого значения. Введите " << nameVar << " повторно: ";

			cin.clear();
			cin.ignore(256, '\n');

			continue;
		}
		else if (userInput == 0)
		{
			cout << endl << "Переменная не может равняться нулю" <<endl;
			cout << "Введите " << nameVar << "повторно: ";
			
			continue; 

		}
		else
		{
			break;
		}
	}

	return userInput;
}

//Вычисление объема
double VolumeCalculation(double r1, double r2, double h)
{
	double volume = 1.f / 3 * pi * h * (pow(r1, 2) + r1*r2 + pow(r2, 2));
	cout << 1.0 / 3;

	return volume;
}

//Вычисление полной поверхности усеченного конуса
double SquareCalculation(double r1, double r2, double l)
{
	double square = pi * (pow(r1, 2) + (r1 + r2) * l + pow(r2, 2));
	

	return square;
}

int main()
{
	system("chcp 1251>nul");

	double r1, r2, h, l;

	cout << "Вычисление объема и полной поверхности усеченного конуса" <<endl <<endl;

	cout << "Введите радиус нижнего основания: ";
	r1 = GetVar("радиус нижнего основания");
	cout << endl << "Введите радиус верхнего основания: ";
	r2 = GetVar("радиус верхнего основания");
	cout << endl << "Введите высоту усечённого конуса: ";
	h = GetVar("высоту");
	
	l = sqrt(pow(h, 2) + pow((r1 - r2), 2));

	cout << endl << endl;
	printf("Объем данного усеченного конуса равен: %.2f\n", VolumeCalculation(r1, r2, h));
	printf("Полная поверхность усеченного конуса равна: %.2f\n", SquareCalculation(r1, r2, l));

	


	system("pause>nul");
	return 0;
}