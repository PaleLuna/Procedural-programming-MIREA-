#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
void ShowMatrix(T** matrix, int rows, int collums)
{
	for (int i = 0; i < rows; i++)
	{
		printf("|%i: ", i+1);
		for (int j = 0; j < collums; j++)
		{
			if (typeid(matrix[i][j]) == typeid(double))
				printf("%-5.2f ", matrix[i][j]);
			else
				printf("%-3i", matrix[i][j]);
		}
		printf("|\n");
	}
}

template<typename T>
void DeleteMatrix(T** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main()
{
	system("chcp 1251>nul");

	//Объявление и инициализация динамического массива (таблицы торговец/кол-во товаров)
	int productCount;
	int traders;
	
	printf("Задайте количество продавцов: ");
	cin >> traders;
	printf("Задайте количество товара: ");
	cin >> productCount;

	int** matrixA = new int* [traders];
	for (int i = 0; i < traders; i++)
	{
		matrixA[i] = new int[productCount];
		printf("Введите количество каждого товара для %i-го продавца:\n", i + 1);
		for (int j = 0; j < productCount; j++)
		{
			cin >> matrixA[i][j];
		}
		cin.ignore(256, '\n');
	}

	//Объявление и инициализация динамического массива (таблицы стоимость/комиссионные)
	int collumsB = 2;
	double** matrixB = new double*[productCount];
	for (int i = 0; i < productCount; i++)
	{
		matrixB[i] = new double[collumsB];
		printf("Введите цену и комиссионые %i-го товара:\n", i + 1);
		for (int j = 0; j < collumsB; j++)
		{
			cin >> matrixB[i][j];
		}
		cin.ignore(256, '\n');
	}

	//Объвления и инициализация динамического массива (таблицы выручка/комиссионные)
	double** matrixC = new double*[traders];

	int traderWithMaximumRevenue = 0;
	int traderWithMinimumRevenue = 0;

	int traderWithMaximumCommissions = 0;
	int traderWithMinimumCommissions = 0;

	double totalComissions = 0;
	double totalRevenue = 0;


	//Вывод первых двух таблиц
	printf("Количество продаваемого товара:\n");
	ShowMatrix(matrixA, traders, productCount);
	printf("Цена и комиссия каждого товара\n");
	ShowMatrix(matrixB, productCount, collumsB);

	//Умножение матриц
	for (int i = 0; i < traders; i++)
	{
		matrixC[i] = new double[collumsB];
		for (int j = 0; j < collumsB; j++)
		{
			matrixC[i][j] = 0;
			for (int k = 0; k < productCount; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
		totalRevenue += matrixC[i][0];
		totalComissions += matrixC[i][1];

		traderWithMaximumRevenue = ((matrixC[i][0] > matrixC[traderWithMaximumRevenue][0]) ? i : traderWithMaximumRevenue);
		traderWithMinimumRevenue = ((matrixC[traderWithMinimumRevenue][0] > matrixC[i][0]) ? i : traderWithMinimumRevenue);

		traderWithMaximumCommissions = ((matrixC[i][1]>matrixC[traderWithMaximumCommissions][1])?i:traderWithMaximumCommissions);
		traderWithMinimumCommissions = ((matrixC[traderWithMinimumCommissions][1]>matrixC[i][1])?i:traderWithMinimumCommissions);
	}

	//Вывод результатов
	printf("Результат произведения\n");
	ShowMatrix(matrixC, traders, collumsB);
	printf("\n\n\n\n");

	printf("Продавец с минимальной выручкой:\n%i: %.2f\n", traderWithMinimumRevenue+1, matrixC[traderWithMinimumRevenue][0]);
	printf("Продавец с максимальной выручкой выручкой:\n%i: %.2f\n\n",traderWithMaximumRevenue+1,matrixC[traderWithMaximumRevenue][0]);

	printf("Продавец с минимальными комиссионными:\n%i: %.2f\n", traderWithMinimumCommissions+1, matrixC[traderWithMinimumCommissions][1]);
	printf("Продавец с максимальными комиссионными:\n%i: %.2f\n\n", traderWithMaximumCommissions+1, matrixC[traderWithMaximumCommissions][1]);

	printf("Общая сумма выручки всех продавцов: %.2f\n", totalRevenue);
	printf("Общая сумма комиссионных всех продавцов: %.2f\n\n", totalComissions);

	//Удаление двумерных динамических массивов
	DeleteMatrix(matrixA, traders);
	DeleteMatrix(matrixB, productCount);
	DeleteMatrix(matrixC, traders);

	system("pause");
	return 0;
}

