#include <iostream>
#include <cmath>

using namespace std;


//Заполнение и вывод массива со значениями 'X'
void FillingArray(int count, float min_x, float step)
{
    float den, numer, funcRes; //Знаменатель, числитель, результат функции
    float* array = new float[count];
    array[0] = min_x;

    for (int i = 1; i < count; i++)
    {
        array[i] = array[i - 1] + step;

    }

    printf("|  x  | F(x)|\n");

    for (int i = 0; i < count; i++)
    {
        if ((array[i] - 1) != 0)
        {
            numer = pow(array[i], 2) - 2 * array[i] + 2;
            den = array[i] - 1;
            funcRes = numer / den;

            printf("|%-5.2f|%5.2f|\n", array[i], funcRes);
        }
        else
        {
            printf("|%-5.2f|NAN  |\n", array[i]);
        }
    }


}

int main()
{
    system("chcp 1251>nul");

    cout << "табуляция функции (x^2 - 2x + 2)/(x - 1)" << endl << endl;

    float x1 = -4;
    int x2 = 4;
    float step = 0.5f;

    int count = ceil((x2 - x1) / step) + 1;

    FillingArray(count, x1, step);


    cout << endl << "Конец программы";

    system("pause>nul");
    return 0;
}
