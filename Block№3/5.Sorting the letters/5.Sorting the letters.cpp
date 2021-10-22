#include <iostream>
#include <fstream>

using namespace std;

//Функция быстрой сортирвки
void QuickSort(char* text, int start, int end)
{
	//Объявление и инициализая переменных
	int leftHold = start;//Указатель, смещающий границу влево
	int rightHold = end;//Указатель, смещающий границу вправо
	char pivot = text[(start+end)/2];//Опорный элемент

	//Пока границы не сомкнулись
	while (leftHold < rightHold)
	{
		//Пока не найден элемент больше опорного справа
		while (tolower(text[leftHold]) < tolower(pivot))
			leftHold++;
		//Пока не найдет элемент меньше опорного слева
		while (tolower(text[rightHold]) > tolower(pivot))
			rightHold--;

		//Если границы не сомкнулись, то указатели обмениюваются значениями
		if (leftHold < rightHold)
		{
			swap(text[leftHold++], text[rightHold--]);
		}
	}

	//Если есть, что сортирвать слева
	if (start < leftHold)
	{
		QuickSort(text, start, leftHold-1);
	}
	//Если есть, что сортировать справа
	if (rightHold < end)
	{
		QuickSort(text, rightHold+1, end);
	}


}

int main()
{
	system("chcp 1251>nul");

	//Объявление переменных
	const int count = 30;
	char text[count];

	//Заполнение массива символов пользовательским вводом
	printf("Введите строку, которую необходимо отсортировать:\n");
	for (int i = 0; i < count; i++)
	{
		cin >> text[i];
	}
	//Отрбасывает лишние символы, что не вошли в массив
	cin.ignore(512, '\n');

	//Сортируем
	QuickSort(text, 0, count-1);

	//Выводим результат
	printf("\nОтсортированная строка:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%c", text[i]);
	}
	
	printf("\n\n\n\n\n\n");
	system("pause");
	return 0;
}