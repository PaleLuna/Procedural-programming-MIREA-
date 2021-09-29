#include <iostream>

using namespace std;

int GetAnswer(string question)
{
	int answer;


	while (true)
	{
		cout << question;
		cin >> answer;

		//Отбрасывание лишних символов из буфера
		cin.ignore(256, '\n');

		//Обработка пользовательского ввода
		if (cin.fail())
		{
			cout << "Упс! Неверней формат ответа, попробуйте еще раз." << endl;

			//Сброс состояния
			cin.clear();

			//Удаляем значения предыдущего ввода
			cin.ignore(256, '\n');
			continue;
		}

		else if ((answer < 0 || answer > 1))
		{
			cout << "Упс! Неверней формат ответа, попробуйте еще раз." << endl;
			continue;
		}

		else
		{
			break;
		}

	}

	return answer;
}

int main()
{
	system("chcp 1251>nul");

	int lampOn, curtainsOpen, day;

	cout << "Ответьте на приведенные ниже вопросы. '0' - нет, '1' - да" << endl << endl;

	lampOn = GetAnswer("Включена ли лампа? ");
	curtainsOpen = GetAnswer("Открыты ли шторы? ");
	day = GetAnswer("На улице день? ");

	if (day && curtainsOpen || lampOn)
		cout << endl << "В комнате светло!";
	else
		cout << endl << "В комнате довольно темно, включите лампу!";

	system("pause>nul");
	return 0;
}