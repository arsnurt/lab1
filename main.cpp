#include <iostream>
#include <limits>
#include <string>
#include <cmath>
using namespace std;

void task1() {
    string s;
    cout << "Enter a valid positive number of the form ab.cd;" << endl;
    cout << "the program will output ab, cd, and a comparison of these numbers to the terminal." << endl;
    cin >> s;
    if (s[0] == '-') {
        cout << "Entered number must be positive!" << endl;
        return;
    }
    else{
        int pos = s.find('.');
        unsigned ab = stoi(s.substr(0, pos));
        unsigned cd = stoi(s.substr(pos + 1));
        cout << ab << " " << cd << endl;
        if (ab > cd) cout << "The first number is bigger." << endl;
        else if (cd > ab) cout << "The second number is bigger." << endl;
        else cout << "The numbers are equal." << endl;
    }
}

void task2() {
    string sx, sk;
    cout << "The program reads the entered real numbers and calculates f(x) using the following formula: " << endl;
    cout << "f(x) = |cos^k(x-3)e^x|, x<1" << endl;
    cout << "f(x)= x^ke^k-k, x>=1" << endl;
    cout << "Enter the value of x: "; cin >> sx;
    cout << "Enter the value of k: "; cin >> sk;
    int digitsX = 0, digitsK = 0;
    for (char c : sx) if (isdigit(c)) digitsX++;
    for (char c : sk) if (isdigit(c)) digitsK++;
    if (digitsX > 15 || digitsK > 15) {
        cout << "The entered values lead to a loss of accuracy and incorrect program execution." << endl;
        return;
    }
    else {
        double x, k;
        x = stod(sx);
        k = stod(sk);
        double result = 0.0;
        if (x < 1.0)
            result = abs(pow(cos(x - 3.0), k)) * exp(x);
        else
            result = pow(x,k) * exp(k) - k;
        cout << "task2 result: " << result << endl;
    }
}

void task3() {
    cout << "The program will determine whether the point belongs to the selected area and display the result on the terminal." << endl;
    cout << "Enter the coordinates of the point (x y):" << endl;
    string sx, sy;
    cin >> sx >> sy;
    int digitsX = 0, digitsY = 0;
    for (char c : sx) if (isdigit(c)) digitsX++;
    for (char c : sy) if (isdigit(c)) digitsY++;
    if (digitsX > 15 || digitsY > 15) {
        cout << "The entered values lead to a loss of accuracy and incorrect program execution." << endl;
        return;
    }
    else {
        double x = stod(sx);
        double y = stod(sy);
        if ((x*x + y*y <= 1.0) && (y <= x*x))
            cout << "The point belongs to the selected area." << endl;
        else
            cout << "The point does not belong to the selected area." << endl;
    }
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}
