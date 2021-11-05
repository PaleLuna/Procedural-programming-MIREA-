#include <iostream>

using namespace std;

void DuplicatingASymbol(short numOfStars, short numOfLine);
void DuplicatingASymbol(short numOfLine);

const char line = '-';
const char star = '*';

int main()
{
	system("chcp 1251>nul");

	//Объявление и инициализация
	const short numOfRows = 13;
	const short numOfRowsWithStar = 6;
	const short numOfStarsInLine = 48/ numOfRowsWithStar;
	const short numOfLineInRow = 48;

	printf("Флаг \"Былая Слава\" 1912 года:\n\n");
	for (short i = 0; i < numOfRows; i++)
	{
		if (i < 6)
		{
			DuplicatingASymbol(numOfStarsInLine, (short)numOfLineInRow - numOfStarsInLine);
			continue;
		}
		DuplicatingASymbol(numOfLineInRow + numOfStarsInLine);
			
	}

	printf("\n\n\n\n\n\n");
	system("pause");
	return 0;
}

void DuplicatingASymbol(short numOfStars, short numOfLine)
{
	for (short i = 0; i < numOfStars; i++)
		printf("%c ", star);
	for (short i = 0; i < numOfLine; i++)
		printf("%c", line);
	printf("\n");
}

void DuplicatingASymbol(short numOfLine)
{
	for (short i = 0; i < numOfLine; i++)
		printf("%c", line);
	printf("\n");
}
