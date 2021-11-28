#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const map<char, int> dictionary
{
    {'A', 10},{'B', 11},{'C', 12},{'D', 13},{'E', 14},{'F', 15},{'G', 16},{'H', 17},{'I', 18},
    {'J', 19},{'K', 20},{'L', 21},{'M', 22},{'N', 23},{'O', 24},{'P', 25},{'Q', 26},{'R', 27},
    {'S', 28},{'T', 29},{'U', 30},{'V', 31},{'W', 32},{'X', 33},{'Y', 34},{'Z', 35}
};

const map<int, char> inverseDictionary
{
    {10, 'A'},{11, 'B'},{12, 'C'},{13,'D'},{14, 'E'},{15, 'F'},{16, 'G',},{17, 'H'},{18, 'I'},
    {19, 'J'},{20, 'K'},{21, 'L'},{22, 'M'},{23, 'N'},{24, 'O'},{25, 'P'},{26, 'Q'},{27, 'R'},
    {28, 'S'},{29, 'T'},{30, 'U'},{31, 'V'},{32, 'W'},{33, 'X'},{34, 'Y'},{35, 'Z'}
};

float NumeralSystemTranslate(char* num, int base, int len)
{
    float result = 0;

    for (int i = len; i >= 0; i--)
    {
        if (dictionary.count((char)toupper(num[i])) > 0 || isdigit((unsigned char)num[i]))
        {
            int numOfBitness = (isdigit(num[i]) ? num[i] - '0' : dictionary.at((char)toupper(num[i])));
            if (numOfBitness < base)
            {
                result += numOfBitness * (int)pow(base, len - i);
                continue;
            }
        }

        return NAN;
    }
    return result;
}


char* NumeralSystemTranslate(int numInTenBase, int targetBase)
{
    int mod;
    int div = numInTenBase;
    char result[256];
    int bitness = 0;

    do
    {
        mod = div % targetBase;
        div = div / targetBase;
        result[bitness++] = ((mod > 9) ? inverseDictionary.at(mod) : (char)mod + '0');
    } while (div >= targetBase);

    result[bitness] = ((div > 9) ? inverseDictionary.at(div) : (char)div + '0');

    if (bitness < 256)
    {
        result[bitness+1] = '\0';
    }

    int leftBorder = 0;
    int rightBorder = bitness;

    while (leftBorder < rightBorder)
    {
        swap(result[leftBorder], result[rightBorder]);
        leftBorder++;
        rightBorder--;
    }
    return result;
}

int main()
{
    system("chcp 1251> nul");

    char num[256];
    int current_base;
    float ten_base = 0;

    int target_base;
    char* result;

    printf("Введите число: ");
    cin.getline(num, 256);
    int bitness = strlen(num) - 1;
    printf("Введите основание числа: ");
    cin >> current_base;
    printf("Введите целевую систему счисления: ");
    cin >> target_base;
   

    //Перевод любой сс (до основания 35) в десятичную
    ten_base = NumeralSystemTranslate(num, current_base, bitness);
    if (isnan(ten_base))
    {
        printf("Неккоректно введенное число!\n");
        system("pause>");
        return 0;
    }
    //Перевод в целевую сс
    result = NumeralSystemTranslate(ten_base, target_base);

    printf("Число в системе счисления по основанию %i: %s\n", target_base, result);



    system("pause");
    return 0;
}