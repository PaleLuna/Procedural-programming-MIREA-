#include <iostream>
#include <cmath>

using namespace std;

int NumberSing(int num)
{
	if(num != 0) return num / abs(num);
	return 0;
}

int main()
{
	system("chcp 1251>nul");
	//Объявление переменных
	int userInput;

	//Инициализация переменных
	cin >> userInput;

	printf("знак числа: %i\n", NumberSing(userInput));

	system("pause");
	return 0;
}