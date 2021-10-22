#include <iostream>
#include <fstream>

using namespace std;

void QuickSort(char* text, int start, int end)
{
	int leftHold = start;
	int rightHold = end;
	char pivot = text[(start+end)/2];

	

	while (leftHold < rightHold)
	{
		while (tolower(text[leftHold]) < tolower(pivot))
			leftHold++;
		while (tolower(text[rightHold]) > tolower(pivot))
			rightHold--;


		if (leftHold < rightHold)
		{
			swap(text[leftHold++], text[rightHold--]);
		}
	}
	
	if (start < leftHold)
	{
		QuickSort(text, start, leftHold-1);
	}
	if (rightHold < end)
	{
		QuickSort(text, rightHold+1, end);
	}


}

int main()
{
	system("chcp 1251>nul");

	//Объявление переменных
	const int count = 12;
	char text[count];

	for (int i = 0; i < count; i++)
	{
		cin >> text[i];
	}
	cin.ignore(512, '\n');

	QuickSort(text, 0, count-1);

	for (int i = 0; i < count; i++)
	{
		printf("%c", text[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}