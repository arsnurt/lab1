#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double task1(double x, double a = 1.0, double b = 2.0);
void task2_table();
double task3();

int main(){
    double x;
    cout << '\n' << endl;
    cout << "ЗАДАНИЕ №1" << endl;
    cout << "Дана формула sin(a + x²) - tan(∛xᵇ)" << endl;
    cout << "Определить значение этой формулы и вывести его на экран." << endl;
    cout << "Параметры a и b зафиксированы в виде произвольных констант типа double." << endl;
    cout << "a = 1.0, b = 2.0" << endl;
    cout << "Число x вводится пользователем с клавиатуры." << endl;
    cout << "Введите значение x: ";
    cin >> x;
    double result = task1(x);
    if(isnan(result)){
        cout << "Введено недопустимое значение x." << endl;
        return 1;
    }
    cout << "Значение выражения в задании 1: " << result << endl;
    cout << '\n';
    // конец задания 1
    cout << "ЗАДАНИЕ №2" << endl;
    cout << "Дана формула: ((a+b)³ - (a³ + 3ab²)) : (3a²b+b³)" << endl;
    cout << "Формулу разделить на отдельные компоненты." << endl;
    cout << "a = 10, b = 0.01\n" << endl;
    cout << "Таблица компонентов и их значений" << endl;
    task2_table();
    // конец задания 2
    cout << "\nЗАДАНИЕ №3" << endl;
    cout << "Вычислить расстояние между двумя точками с координатами (x1, y1) и (x2, y2)" << endl;
    task3();
    return 0;    

}
double task1(double x, double a, double b){
    double result = sin(a + pow(x, 2.0)) - tan(cbrt(pow(x, b)));
    if (isnan(result) || isinf(result)){
        cout << "Введенное значение недопустимо.";
        return NAN;
    }
    return result;
}
void task2_table(){
    // значение выражения для float
    float a_f = 10.0f, b_f = 0.01f;
    double a_d = 10.0, b_d = 0.01;

    float comp1_f = a_f + b_f;
    double comp1_d = a_d + b_d;

    float comp2_f = pow(comp1_f, 3.0f);
    double comp2_d = pow(comp1_d, 3.0);

    float comp3_f = pow(a_f, 3.0f);
    double comp3_d = pow(a_d, 3.0);

    float comp4_f = 3.0f * a_f * pow(b_f, 2.0f);
    double comp4_d = 3.0 * a_d * pow(b_d, 2.0);
    
    float comp5_f = comp3_f + comp4_f;
    double comp5_d = comp3_d + comp4_d;
    
    float comp6_f = comp2_f - comp5_f; // числитель
    double comp6_d = comp2_d - comp5_d; // числитель
    
    float comp7_f = 3.0f * pow(a_f, 2.0f) * b_f;
    double comp7_d = 3.0 * pow(a_d, 2.0) * b_d;
    
    float comp8_f = pow(b_f, 3.0f);
    double comp8_d = pow(b_d, 3.0);
    
    float comp9_f = comp7_f + comp8_f; // знаменатель    
    double comp9_d = comp7_d + comp8_d; // знаменатель    
    
    float result_f = comp6_f / comp9_f;
    double result_d = comp6_d / comp9_d;
    
    // Вывод таблицы
    cout << fixed << setprecision(10);
    cout << "-------------------------------------------------------------" << endl;
    cout << "Компонент\t\tЗначение float\t\tЗначение double" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "a + b\t\t\t" << comp1_f << "\t\t" << comp1_d << endl;
    cout << "(a+b)³\t\t\t" << comp2_f << "\t\t" << comp2_d << endl;
    cout << "a³\t\t\t" << comp3_f << "\t\t" << comp3_d << endl;
    cout << "3ab²\t\t\t" << comp4_f << "\t\t" << comp4_d << endl;
    cout << "a³ + 3ab²\t\t" << comp5_f << "\t\t" << comp5_d << endl;
    cout << "Числитель\t\t" << comp6_f << "\t\t" << comp6_d << endl;
    cout << "3a²b\t\t\t" << comp7_f << "\t\t" << comp7_d << endl;
    cout << "b³\t\t\t" << comp8_f << "\t\t" << comp8_d << endl;
    cout << "Знаменатель\t\t" << comp9_f << "\t\t" << comp9_d << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "РЕЗУЛЬТАТ\t\t" << result_f << "\t\t" << result_d << endl;
    cout << "-------------------------------------------------------------" << endl;
}
double task3(){
    double x1, y1, x2, y2, result;
    cout << "Введите координаты (x1 y1) первой точки: ";
    cin >> x1 >> y1;
    cout << "Введите координаты (x2 y2) второй точки: ";
    cin >> x2 >> y2;
    result = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
    cout << result << endl;
    return result;
}