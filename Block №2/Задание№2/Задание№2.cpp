#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int ChekCin()
{
	int userInput;

	while (true)
	{
		cin >> userInput;

		if (cin.fail())
		{
			cout << "Произошла ошибка! Повторите попытку.";

			cin.clear();
			cin.ignore(256, '\n');

			continue;
		}
		else
		{
			break;
		}
	}

	return userInput;
}

int main()
{
	system("chcp 1251>nul");


	
	system("pause>nul");
	return 0;
}