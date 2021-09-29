#include <iostream>

using namespace std;

int GetNum(char nameNum)
{
	int userInput;

	while (true)
	{

		cin >> userInput;

		//Очистка буфера от лишних символов
		cin.ignore(256, '\n');

		//Проверка на корректность введенных данных
		if (cin.fail())
		{
			cout << endl << "Неверный формат ввода" << endl;
			cout << "Введите число '" << nameNum << "' повторно: ";

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

	int a, b;

	cout << "Введите число 'a': ";
	a = GetNum('a');
	cout << endl << "Введите число 'b': ";
	b = GetNum('b');
	cout << endl;

	cout << "Сумма: " << a + b << endl;
	cout << "Разность: " << a - b << endl;
	cout << "Произведение: " << a * b << endl;

	if (b != 0 && a % b == 0) cout << "Частное: " << a / b << endl;

	system("pause>nul");

	return 0;

}