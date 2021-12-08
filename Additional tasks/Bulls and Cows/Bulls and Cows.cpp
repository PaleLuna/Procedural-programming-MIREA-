#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(0));

	ifstream file("text.txt");
	if (file.is_open())
	{
		char text[512];
		file.getline(text, 512, '\0');
		printf("%s\n\n", text);
	}

	//Объявление переменных
	const short int countDigits = 5; //Количество цифр (с запасом для nul символа)
	char conceivedNumber[countDigits]; //Символьный массив, хранящий загаданное число

	char userNum[countDigits]; //Символьный массив, хранящий число пользователя
	
	char result[countDigits]; //Символьный массив, хранящий результат совпадений

	char currentNum; //Текущая цифра
	int counter = 0; //Счетчик

	currentNum = (1 + rand() % 10) + '0';
	conceivedNumber[counter] = currentNum;

	//Заполнение массива
	while (counter < countDigits-1)
	{
		bool isEx = false; //Исключение
		currentNum = (rand() % 10) + '0';//Текущая цифра

		//Поиск совпадающий цифр
		for (int j = 0; j <= counter; j++)
		{
			if (conceivedNumber[j] == currentNum)
			{
				isEx = true;
				break;
			}
		}
		
		if(!isEx) conceivedNumber[++counter] = currentNum;
	}
	//Указываем конец строки
	conceivedNumber[countDigits-1] = '\0';

	printf("Введите своё число или \'0\', если хотите закончить игру\n");

	int currect = 0;
	while (currect < 4)
	{
		printf("Ваше число: ");
		cin.getline(userNum, countDigits);

		if (strlen(userNum) < 4)
		{
			if ((strlen(userNum) == 1) && (userNum[0] == '0'))
			{
				printf("Выходим...\n\n");
				printf("Загаданное число компьютером: %s\n\n", conceivedNumber);
				system("pause");
				return 0;
			}
			printf("Введено некорректное число!\n");
			continue;
		}
		
		//Поиск совпадений
		counter = 0;
		currect = 0;
		for (int i = 0; userNum[i]; i++)
		{
			for (int j = 0; conceivedNumber[j]; j++)
			{
				if (userNum[i] == conceivedNumber[j])
				{
					if (j == i)
					{
						result[counter++] = '+';
						currect++;
						break;
					}

					result[counter++] = '-';
					break;
				}
			}
		}
		
		if (counter == 0)
		{
			printf("Совпадений нет!\n");
			continue;
		}
		result[counter] = '\0';
		printf("Совпадения: %s\n", result);
		
	}

	printf("Ура, Вы победили!\n\n\n");
	printf("Загаданное число компьютером: %s", conceivedNumber);



	system("pause");
	return 0;
}