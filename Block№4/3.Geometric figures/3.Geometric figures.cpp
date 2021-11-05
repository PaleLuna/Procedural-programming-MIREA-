#include <iostream>

using namespace std;

float RectangleSquare();
float TriangleSquare();
float CircleSquare();

int main()
{
	system("chcp 1251>nul");

	printf("Площадь прямоугольника: %.2f\n\n", RectangleSquare());
	printf("Площадь треугольника: %.2f\n\n", TriangleSquare());
	printf("Площадь круга: %.2f\n\n", CircleSquare());
	
	printf("\n\n");
	system("pause");
	return 0;
}

float RectangleSquare()
{
	float a, b, s;

	printf("Площадь прямоуголька. Введите следующие переменные:\n");
	printf("Сторона \"a\": ");
	cin >> a;
	printf("Сторона \"b\": ");
	cin >> b;

	s = a * b;
	return s;
}

float TriangleSquare()
{
	float a, h, s;

	printf("Площадь треуголька. Введите следующие переменные:\n");
	printf("Основание \"a\": ");
	cin >> a;
	printf("Высоту \"h\": ");
	cin >> h;

	s = h * a / 2;

	return s;
}

float CircleSquare()
{
	float r, s;
	const float pi = 3.14;

	printf("Площадь круга. Введите следующие переменные:\n");
	printf("Радиус окружности \"r\": ");
	cin >> r;

	s = pi * r * r;

	return s;
}