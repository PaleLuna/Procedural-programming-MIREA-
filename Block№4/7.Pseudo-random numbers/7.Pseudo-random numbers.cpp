#include <iostream>
#include <Windows.h>

using namespace std;



int GeneratorOfNumbers(int s, int i, int m, int a, int c);

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
	int i = End - Start;


	int result = GeneratorOfNumbers(s, i, m, a, c);

	printf("Генератор псевдослучайных чисел\n\n");
	
	printf("%i\n", result);
	


	system("pause>nul");
	return 0;
}

int GeneratorOfNumbers(int s, int i, int m, int a, int c)
{
	if (i <= 0)
	{
		return s;
	}
	s += (m * (GeneratorOfNumbers(s, --i, m, a, c)) + a) % c;
	return s;
}
