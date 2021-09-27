#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	system("chcp 1251>nul");

	string name;

	cout << "Введите имя: ";
	cin >> name;
	cout << endl;

	cout << "Вас зовут " << name << endl;

	system("pause>nul");

	return 0;

}