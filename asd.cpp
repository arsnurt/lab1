#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void pepe1() {
    cout << "Задание 1\nВВедите значения x и n через пробел: ";
    double x, n, y = 0;
    cin >> x >> n;
    if (x < 0.)
    {
        for (int i = 1; i < (n - 1); i++)
        {
            for (int j = 1; j < n; j++)
            {
                y += x - double(pow(i, 2) - j);
            }
        }
    }
    else
    {
        for (int i = 0; i < (n - 1); i++)
        {
            y += ((x - 1) / (i + 1));
        }
    }
    cout << "y = ";
    cout << y << "\n\n";
}

bool check(char x, string y)
{
    for (char i : y)
    {
        if (i == x) return 0;
    }
    return 1;
}

int ishet(char x, string y)
{
    int num = 0;
    for (char i : y)
    {
        if (i == x)
        {
            num++;
        }
    }
    return num;
}

bool simple(int x)
{
    for (int i = 1; i < x; i++)
    {
        if ((x % i) != 0) continue;
        else return false;
    }
    return true;
}

bool povtor(int x)
{
    string strx = to_string(x);
    for (int i = 1; i < 10; i++)
    {
        char a = i;
        if (ishet(a, strx) > 0) return false;
        else continue;
    }
    return true;
}


void pepe2()
{
    cout << "Задание 2\nПункт 8\nВведите число для подсчета количества каждой из цифр этого числа: \n";
    string qwerty = "";
    string n;
    cin >> n;
    for (char i : n)
    {
        if (check(i, qwerty))
        {
            cout << i << ":" << "\t" << ishet(i, n) << "\n";
            qwerty += i;
        }
        else continue;
        cout << "Пункт 19\nВведите число N: ";
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            if ((simple(i) and povtor(i)))
            {
                cout << i;
            }
            else continue;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    pepe1();
    pepe2();
    return 0;
}