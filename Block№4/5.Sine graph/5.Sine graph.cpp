#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

const double pi = 3.14159265358979323846;

int main()
{
	system("chcp 1251>nul");

	const int offset = 14;
	const int amplitude = offset;
	const int frequency = 18;

	COORD position2D;

	for (int x = 0; x < 109; x++)
	{
		position2D.X = x;
		position2D.Y = -(int)(amplitude * sin(pi/ frequency * x)) + offset;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position2D);
		printf("*");
	}

	system("pause>nul");
	return 0;
}