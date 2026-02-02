#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void pepe1() {
    cout << "Задание 1. " << endl;
    cout << "Σ(i=1..n-1) Σ(j=1..n) (x - i^2 + j), если x<0" << endl;
    cout << "Σ(i=0..n-1) (x-1)/(i+1), если x>=0." << endl;
    cout << "Введите значения x, n через пробел: " << endl;
    double x;
    int n;
    cin >> x >> n;
    double y = 0;
    if (x < 0) {
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= n; j++) {
                y += x - (i * i) + j;
            }
        }
    } else {
        for (int i = 0; i <= n - 1; i++) {
            y += (x - 1.0) / (i + 1.0);
        }
    }
    cout << "y = " << y << "\n\n";
}

bool check(char x, string y) {
    for (char i : y) {
        if (i == x) return false;
    }
    return true;
}

int ishet(char x, string y) {
    int num = 0;
    for (char i : y)
        if (i == x) num++;
    return num;
}

bool simple(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

bool povtor(int x) {
    string s = to_string(x);
    bool used[10] = { false };
    for (char c : s) {
        int d = c - '0';
        if (used[d]) return false;
        used[d] = true;
    }
    return true;
}

void pepe2() {
    cout << "Задание 8." << endl;
    cout << "Для заданного натурального числа N подсчитать сколько раз встречается каждая из его цифр в этом числе.";
    string s;
    cin >> s;
    cout << "\nКоличество каждой цифры:\n";
    string used = "";
    for (char c : s) {
        if (check(c, used)) {
            cout << c << " : " << ishet(c, s) << endl;
            used += c;
        }
    }
}

void pepe19(){
    cout << "Задание 19. " << endl;
    cout << "Найти все простые числа, не превосходящие заданного числа N, в десятичном представлении которых нет совпадающих цифр." << endl;
    int N;
    cout << "Введите число N: " << endl;
    cin >> N;
    cout << "Простые числа, меньшие или равные N без повторяющихся цифр: " << endl;
    for (int i = 2; i <= N; i++) {
        if (simple(i) && povtor(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    pepe1();
    pepe2();
    pepe19();
    return 0;
}
