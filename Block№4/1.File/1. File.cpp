#include <iostream>
#include <fstream>

using namespace std;

int ConvertToInt(char num)
{
	return num - '0';
}

int main()
{
	system("chcp 1251>nul");

	const int count = 10;
	char userInput;
	int sum = 0;

	char textOnFile[256];

	fstream file;
	file.open("text.txt", ios_base::out);

	printf("Запишите в файл %i цифр", count);
	for (int i = 0; i < count; i++)
	{
		cin >> userInput;
		file << userInput;
	}

	file.close();
	file.open("text.txt", ios_base::in);

	if (file.is_open())
	{
		file.getline(textOnFile, 256);

		for (int i = 0; textOnFile[i]; i++)
		{
			sum += ConvertToInt(textOnFile[i]);
		}

		printf("%i", sum);
	}

	else
	{
		printf("Файл не существует");
	}

	


	printf("\n\n\n\n");
	system("pause");
	return 0;
}