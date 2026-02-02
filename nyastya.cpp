#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void pepe1() {
    cout << "Задание 1\nВведите значения x и n через пробел: ";
    double x, n;
    cin >> x >> n;
    double y = 0;
    if (x < 0.) {
        for (int i = 1; i < (int)(n - 1); i++) {
            for (int j = 1; j < (int)n; j++) {
                y += x - (pow(double(i), 2.0) - double(j));
            }
        }
    } else {
        for (int i = 0; i < (int)(n - 1); i++) {
            y += (x - 1.0) / double((i + 1));
        }
    }
    cout << "y = " << y << "\n\n";
}

bool check(char x, string used) {
    for (char i : used)
        if (i == x) return false;
    return true;
}

int ishet(char x, string s) {
    int count = 0;
    for (char i : s)
        if (i == x) count++;
    return count;
}

bool prostoe(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool povtor(int x) {
    string s = to_string(x);
    for (char c : s) {
        int k = 0;
        for (char d : s) {
            if (c == d) k++;
        }
        if (k > 1) return false;
    }
    return true;
}

void pepe2() {
    cout << "Задание 2\nПункт 8\nВведите число для подсчета количества каждой цифры: ";
    string n;
    cin >> n;
    string used = "";
    for (char c : n) {
        if (check(c, used)) {
            cout << c << " : " << ishet(c, n) << "\n";
            used += c;
        }
    }
    cout << "Пункт 19\nВведите число N: ";
    int number;
    cin >> number;
    cout << "Простые числа без повторяющихся цифр до " << number << ":\n";
    for (int i = 2; i <= number; i++) {
        if (prostoe(i) && povtor(i)) {
            cout << i << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    pepe1();
    pepe2();
    return 0;
}
