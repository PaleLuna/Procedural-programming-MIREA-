#include <iostream>

using namespace std;

void QuickSort(int* array, int startIndex, int endIndex)
{
	int leftPointer = startIndex;//Указатель слева
	int rightPointer = endIndex;//Указатель справа
	int pivot = array[(endIndex + startIndex) / 2];//Опорный элемент

	/// <summary> 
	/// перераспределение элементов в массиве таким образом, 
	/// что элементы, меньшие опорного, помещаются перед ним,
	/// а большие или равные - после.
	///</summary>

	//Цикл, перебирающий массив в заданных границах 
	while (leftPointer <= rightPointer)
	{
		//Смещение левого указателя
		while ((array[leftPointer] < pivot))
			leftPointer++;
		//Смещение правого указателя
		while ((array[rightPointer] > pivot))
			rightPointer--;

		//Обмен элементов
		if (leftPointer <= rightPointer)
		{
			swap(array[leftPointer++], array[rightPointer--]);
		}
	}

	//Рекурсивное разбие массива на две части
	if (rightPointer > startIndex)
		QuickSort(array, startIndex, rightPointer);
	if (leftPointer < endIndex)
		QuickSort(array, leftPointer, endIndex);
}

void Show(int* array, int len)
{
	printf("{%i", array[0]);
	for (int i = 1; i < len; i++)
	{
		printf(", %i", array[i]);
	}
	printf("}\n\n");
}

int main()
{
	system("chcp 1251>nul");

	int theAnswerToAllQuestions = 42;

	srand(theAnswerToAllQuestions);

	const int len = 10;
	int array[len];

	for (int i = 0; i < len; i++)
	{
		array[i] = 1 + rand() % theAnswerToAllQuestions;
	}
	printf("Массив до сортировки:\n");
	Show(array, len);
	
	QuickSort(array, 0, len - 1);

	printf("Массив после сортировки:\n");
	Show(array, len);


	system("pause");
	return 0;
}