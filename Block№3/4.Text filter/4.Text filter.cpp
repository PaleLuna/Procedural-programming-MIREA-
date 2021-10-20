#include <iostream>
#include <fstream>

using namespace std;

//Вычисление истинной длины текста
int StrLen(char* text)
{
	int len = 0;

	for (int i = 0; text[i]; i++)
	{
		len++;
	}
	
	return len;
}

int main()
{
	system("chcp 1251>null");

	//Объявление переменных
	char text[512];//Весь текст
	int len;
	char* digitStr; //Строка числа
	int numCount = 0; //Будущая длины строки числа

	//Открытие файла
	ifstream file("text.txt");
	
	if (file.is_open())
	{
		file.getline(text, 512);
		len = StrLen(text);
		digitStr = new char[len];//Инициализация динамического массива символов
		
		printf("Все числа в тексте:\n");
		if (len > 0)
		{
			//Перебор символов
			for (int i = 0; i < len; i++)
			{
				//Запись цифр в строку
				if (isdigit(text[i]))
				{
					digitStr[numCount] = text[i];
					numCount++;
				}
				else
				{
					if (numCount > 0)
					{
						//Установка следующего элемента нулевым символом
						if (numCount < len)
						{
							digitStr[numCount] = '\0';
						}

						//Вывод строки
						printf("%s\n", digitStr);

						//Сброс символов в нулевое значение
						for (int j = 0; j < numCount; j++)
						{
							digitStr[j] = '\0';
						}
						//Сброс длины строки цифр
						numCount = 0;
					}
					
				}
			}
			//Вывод последнего числа
			printf("%s\n", digitStr);

			//Удаление динамического массива
			delete[] digitStr;

		}

		else
		{
			printf("Файл пустой.\n");
			return 0;
		}

	}
	else
	{
		printf("Имя файла указано неправильно или его не существует.\n");
	}

	system("pause");
	return 0;
}