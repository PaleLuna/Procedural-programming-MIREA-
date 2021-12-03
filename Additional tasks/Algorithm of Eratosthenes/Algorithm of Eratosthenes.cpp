#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>nul");

	printf("Реализация алгоритма Эратосфена\n\n\n");

	//Объявление и иницализация переменных
	int len = 0;
	int* arrayOfNums;

	printf("Введите натуральное число, соответствующее диапозону простых чисел: ");
	cin >> len;

	arrayOfNums = new int[++len];

	for (int i = 0; i < len; i++)
	{
		arrayOfNums[i] = i;
	}
	arrayOfNums[1] = 0;

	for (int i = 2; i < len; i++)
	{
		if (arrayOfNums[i] != 0)
		{
			for (int j = i*i; j < len; j += i)
			{
				arrayOfNums[j] = 0;
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (arrayOfNums[i] != 0)
		{
			printf("%i\n", arrayOfNums[i]);
		}
	}




	delete[] arrayOfNums;
	system("pause");
	return 0;
}