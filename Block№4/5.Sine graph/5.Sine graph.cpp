#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

const double pi = 3.14159265358979323846;

int main()
{
	system("chcp 1251>nul");

	const int offset = 14;
	const int amplitude = offset-2;
	const float frequency = 1.2;

	COORD position2D;

	for (int x = 0; x < 110; x++)
	{
		position2D.X = x;
		position2D.Y = -(int)(amplitude * sin((x/ pi)*frequency)) + offset;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position2D);
		printf("*");
	}

	system("pause>nul");
	return 0;
}