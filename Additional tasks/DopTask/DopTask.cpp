#include <iostream>
#include <cmath>

using namespace std;

bool SearchingNumberThree(int num)
{
	int div;
	int digits = 0;

	do
	{
		div = num / (int)pow(10, digits++);
		if (div % 10 == 3)
		{
			return true;
		}

	} while (div > 1);

	return false;
}

bool SearchingNumberThree(char* num)
{
	for (int i = 0; num[i]; i++)
	{
		if (num[i] == '3')
			return true;
	}

	return false;
}

int main()
{
	system("chcp 1251>nul");

	char userInput[256];
	int userNum = 0;
	int len;
	
	cin.getline(userInput, 256);
	len = strlen(userInput) - 1;

	for (int i = 0; i <= len; i++)
	{
		int res = (userInput[i] - '0') * (int)pow(10, len - i);
		userNum += res;
	}

	printf("Число в формате строки: %s\nЧисло в формате int: %i\n", userInput, userNum);

	if (SearchingNumberThree(userNum) && SearchingNumberThree(userInput))
	{
		printf("В веденном числе %i есть цифра три!\n\n\n", userNum);
		system("pause");
		return 0;
	}

	printf("В веденном числе %i нет цифры три!\n\n\n", userNum);


	system("pause");
	return 0;
}