#include <iostream>
#include <map>

using namespace std;

const map<char, int> romanNumerals =
{
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};

bool NumberIsCorrect(char* num);

int main()
{
	system("chcp 1251>nul");

	const short	len = 256;
	short realLen;
	char userRomanNumeral[len];
	char userInput;
	
	int indexOfPrevious;
	int checkNumber = 0;
	int decodedNumber = 0;


	printf("Введите римское число: ");
	cin.getline(userRomanNumeral, len);
	realLen = (short)strlen(userRomanNumeral);

	if (!NumberIsCorrect(userRomanNumeral))
	{
		printf("Вы ввели некорректное значение!\n");

		system("pause");
		return 0;
	}

	for (int i = realLen - 1; i >= 0; i--)
	{
		indexOfPrevious = ((i < realLen - 1) ? i + 1 : i);

		short currentNum = (short)romanNumerals.at((char)toupper(userRomanNumeral[i]));
		short previosNum = (short)romanNumerals.at((char)toupper(userRomanNumeral[indexOfPrevious]));

		if ((currentNum < previosNum) && ((currentNum == 1 || currentNum % 10 == 0) && (previosNum == currentNum * 5 || previosNum == currentNum * 10)))
		{
			decodedNumber -= currentNum;
			checkNumber = currentNum;
			continue;
		}

		else if ((currentNum >= previosNum) && (currentNum > checkNumber))
		{
			decodedNumber += currentNum;
			continue;
		}

		printf("Вы ввели некорректное значение!\n");

		system("pause");
		return 0;

	}


	printf("Арабское число: %i\n", decodedNumber);
	
	system("pause");
	return 0;
}

bool NumberIsCorrect(char* num)
{
	short repetitionCounter = 0;
	char savedSymb = num[0];

	for (int i = 0; num[i]; i++)
	{	
		if (romanNumerals.count((char)toupper(num[i])) == 0)
			return false;

		if (num[i] == savedSymb)
			repetitionCounter++;
		else
		{
			savedSymb = num[i];
			repetitionCounter = repetitionCounter * 0 + 1;
		}
		
		if (repetitionCounter > 3)
			return false;
		
	}

	return true;
}