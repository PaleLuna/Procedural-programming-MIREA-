#include <iostream>
#include <cmath>

using namespace std;

double GetUserInput(char varName)
{
	double userInput;
	if (varName == 'x')
	{
		printf("Введите переменную '%c'(не равную нулю): ", varName);
	}
	else
		printf("Введите переменную '%c': ", varName);

	while (true)
	{
		cin >> userInput;

		if (userInput == 0)
		{
			printf("Переменная '%c' не должна равняться нулю. Введите переменную повторно\n", varName);

			continue;
		}
		else
			break;
	}

	return userInput;
}

double GetLn(double a, double x)
{
	double result = a * log(abs(x));
	return result;
}

double GetSqrt(double a, double x)
{
	double result = a - pow(x, 2);
	if (result < 0)
	{
		return NAN;
	}
	else
	{
		return sqrt(result);
	}
}

int main()
{
	system("chcp 1251>nul");

	double x, a, result;

	//получение переменных
	a = GetUserInput('a');
	x = GetUserInput('x');

	if (abs(x) < 1)
	{
		printf("a*ln(|x|) = %.2f", GetLn(a, x));
	}

	else if(abs(x) >= 1)
	{
		printf("sqrt(a - x^2)");
		result = GetSqrt(a, x);
		if (!isnan(result))
		{
			printf(" = %.2f\n", result);
		}
		else
		{
			printf("\nРешений нет\n");
		}
		
	}


	system("pause>nul");
	return 0;
}