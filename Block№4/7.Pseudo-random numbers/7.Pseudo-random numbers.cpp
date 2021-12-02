#include <iostream>
#include <Windows.h>

using namespace std;



int GeneratorOfNumbers(int* array, int s, int i, int m, int a, int c);

int main()
{
	system("chcp 1251>nul");

	//Объявление переменных
	int s = 50;
	int Start = 3;
	int End = 100;
	int m = 37;
	int c = -64;
	int a = 5;
	int count = End - Start;

	int* array = new int[count];
	printf("Генератор псевдослучайных чисел\n\n");
	GeneratorOfNumbers(array, s, count, m, a, c);

	for (int j = 0; j < count; j++)
	{
		printf("%-2i:%-4i| ", j+Start, array[j]);
		if ((j != 0) && (j % 10 == 0))
		{
			printf("\n");
		}

	}

	delete[] array;

	system("pause>nul");
	return 0;
}

int GeneratorOfNumbers(int* array, int s, int i, int m, int a, int c)
{
	if (i == 0)
	{
		array[i] = s;
		return s;
	}
	s += (m * (GeneratorOfNumbers(array, s, i-1, m, a, c)) + a) % c;
	array[i] = s;
	return s;
}
