#include <iostream>
#include <fstream>

using namespace std;

//Функция, возвращающая длину строки
int StrLen(char* text)
{
	int len = 0;
	for (int i = 0; text[i]; i++)
		len++;

	return len;
}

int main()
{
	system("chcp 1251>nul");

	//Переменные
	const int sizeText = 256;
	char text[sizeText];
	ifstream file("text.txt", ios_base::in);

	if (!file.is_open())
	{
		printf("Путь к файлу указан неверно или он не создан!");
		return 0;
	}
	else
	{
		file.getline(text, sizeText);

		if (StrLen(text) == 0)
		{
			printf("Файл пустой.\n");
		}
		else
		{
			printf("%s\n", text);
		}
	}	

	system("pause");
	return 0;
}