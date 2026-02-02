#include <iostream>
#include <iomanip>
using namespace std;

void task1(){
    double x, y;
    cout << "Task 1. Find the value of y based on the value of x. " << endl;
    cout << "if x<0: y = √(-x)" << endl;
    cout << "if 0 <= x <= 10: y = sin x^(0.5)" << endl;
    cout << "if x > 10: y = -ln(x + 120/x)" << endl;
    cout << "Enter the value of x: " << endl;
    cin >> x;
    if (x < 0) {y = sqrt(-x);}
    else if (x >= 0 && x <= 10) {y = sin(pow(x, x + 0.5));}
    else {y = -log(x + (120.0 / x));}
    cout << fixed << setprecision(3) << "The value of y: " << y << endl;
}

void task2(){
    float p1, p2, p3;
    cout << "Task 2. 3 passengers in taxi." << endl;
    cout << "Enter positive numbers p1, p2, p3 (p1<p2<p3):" << endl;
    cin >> p1 >> p2 >> p3;
    while(!((p1 < p2) && (p2 < p3)) || p1 <= 0 || p2 <= 0 || p3 <= 0){
        cout << "Ошибка! Введены числа, противоречащие условию p1<p2<p3. Попробуйте другие числа. " << endl;
        cin >> p1 >> p2 >> p3;
    }
    float pas1 = p1 / 3.0f;
    float pas2 = pas1 + ((p2 - p1) / 2.0f);
    float pas3 = pas2 + (p3 - p2);
    cout << fixed << setprecision(2) << pas1 << '\t' << pas2 << '\t' << pas3 << endl;
}

void task3(){
    double x, a, c, L;
    cout << "Enter values of x, a, c: " << endl;
    cin >> x >> a >> c;
    while((exp(1.0) - pow(cos(pow(x, 2.0) * pow(a, 5.0)), 4.0)) < 0.0){
        cout << "Error! Negative number under the square root. Try different numbers. " << endl;
        cin >> x >> a >> c;
    }
    while(exp(1.0) * sqrt(abs(a + x * pow(c, 4.0))) == 0.0){
        cout << "Error! Division by zero! Try different numbers. " << endl;
        cin >> x >> a >> c;
    }
    double nominator = sqrt(pow(exp(1.0), x) - pow(cos(pow(x, 2.0) * pow(a, 5.0)), 4.0)) + pow(atan(a - pow(x, 5.0)), 4.0);
    double denominator = exp(1.0) * sqrt(abs(a + x * pow(c, 4.0)));
    L = nominator / denominator;
    cout << "L: " << L << endl;
}

void task3_1(){
    double x, y, t, P;
    cout << "Enter values of x, y, t: " << endl;
    cin >> x >> y >> t;
    while((2.0 * y + 3.0 * x) <= 0.0){
        cout << "Error! Negative number or zero in logarithm argument. Try different numbers. " << endl;
        cin >> x >> y >> t;
    }
    while(x < 0.0){
        cout << "Error! Negative number under the square root. Try different value of x. " << endl;
        cin >> x;
    }
    while((t==0 && x == 0.0)){
        cout << "Error! Division by zero! Try different values of x, t. " << endl;
        cin >> x >> t;
    }
    P = (pow(sin(x), 3.0) + log(2.0 * y + 3.0 * x)) / (pow(t, exp(1.0)) + sqrt(x));
    cout << "P: " << P << endl;
}

int main(){
    task1();
    task2();
    task3();
    task3_1();
    return 0;
}