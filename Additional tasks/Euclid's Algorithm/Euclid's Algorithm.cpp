#include <iostream>

using namespace std;


int main()
{
	system("chcp 1251>nul");


	//Объявление и инициализация переменных
	int userNum1 = 0;//Первое число
	int userNum2 = 0;//Второе число

	int num1 = 0;//Рабочая копия первого числа
	int num2 = 0;//Рабочая копия второго числа
	int NOD1 = 0;//Наибольший общий делитель(Делением)
	int NOD2 = 0;//Наибольший общий делитель(Вычитанием)

	printf("%34c****Поиск наибольшего общего делителя двух чисел****\n\n\n", ' ');

	//Реализация пользовательского ввода
	printf("Введите первое число: ");
	cin >> userNum1;
	printf("Введите второе число: ");
	cin >> userNum2;

	num1 = userNum1;
	num2 = userNum2;

	//Поиск НОД(наибольшего общего делителя) делением
	while ((num1 != 0) && (num2 != 0))
	{
		if (num1 > num2) num1 %= num2;

		else num2 %= num1;	
	}

	NOD1 = num1 + num2;

	num1 = userNum1;
	num2 = userNum2;

	//Поиск НОд(наибольшего общего делителя) вычитанием
	while (num1 != num2)
	{
		if (num1 > num2) num1 -= num2;
		else num2 -= num1;
	}

	NOD2 = num1;
	if (NOD1 == NOD2)
	{
		printf("Наибольший общий делитель чисел %i и %i равен %i\n\n\n", userNum1, userNum2, NOD1);
		
		system("pause");
		return 0;
	}
	
	printf("Упс...");



	system("pause");
	return 0;
}