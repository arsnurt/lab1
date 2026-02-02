#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int arrsize = 1000000;

double factorial(int n) {
    double f = 1.;
    for (int i = 1; i <= n; i++) f *= (double)i;
    return f;
}

double inputcheck() {
    string s;
    cin >> s;
    int digits = 0;
    for (char c : s) {
        if (isdigit(c)) digits++;
    }
    if (digits > 15) {
        cout << "The number entered is too large (small)." << endl;
        return NAN;
    }
    return stod(s);
}

void task4_6(){
    int n;
    cout << "General task 4.6: Working with arrays" << endl;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    if ((!cin) || (n <= 0) || (n > arrsize)){cout << "Error: array size must be positive and do not exceed 1000000." << endl; return;}
    double* A = new double[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++){
        cout << "A[" << i << "] = ";
        A[i] = inputcheck();
        if(isnan(A[i])){delete[] A; return;}
    }
    cout << "Array: " << endl;
    for (int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
    delete[] A;
}

void task13_1(){
    int n;
    cout << "Task 13_1: Checking an array" << endl;
    cout << "Enter the size of the array: ";
    cin >> n;
    if ((!cin) || (n <= 0) || (n > arrsize)){
        cout << "Error: array size must be positive." << endl;
        return;
    }
    double* A = new double[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++){
        cout << "A[" << i << "] = ";
        A[i] = inputcheck();
        if(isnan(A[i])){delete[] A; return;}
    }
    bool found = false;
    for (int i = 0; (i < n) && (!found); i++){
        for (int j = i + 1; j < n; j++){
            if (A[i] == A[j]) {found = true; break;}
        }
    }
    if (found){cout << "There are identical elements in the array." << endl;}
    else {cout << "All elements of the array are different." << endl;}
    delete[] A;
}

void task13_2() {
    cout << "Task 13_2: Sum of a series." << endl;
    double x, eps;
    cout << "Enter x: ";
    x = inputcheck();
    cout << "Enter the precision of ε: ";
    eps = inputcheck();
    if ((!cin) || (eps <= 0.0)) {cout << "Error: ε must be positive and do not exceed 1000000." << endl; return;}
    double S = 0.0;
    int k = 0;
    while (true) {
        double term = (pow(-1.0, double(k)) * pow(x, double(k))) / (factorial(2 * k));
        S += term;
        if (fabs(term) < eps) break;
        k++;
    }
    cout << "Sum of a series = " << S << endl;
}

int main(){
    task4_6();
    task13_1();
    task13_2();
    return 0;
}