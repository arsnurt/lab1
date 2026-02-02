#include <iostream>
using namespace std;

class Point
{
public:
    int x_1, y_1;
    double x_d, y_d;
    void set_point(int x, int y);
    void set_point(double x, double y);
} point_1, point_2;

template <class X, class Y, class Z> void equal(X num1, Y num2, Z num3)
{
    cout << num1 << endl;
}

int main(){
    point_1.set_point(3, 7);
    point_2.set_point(3.4, 7.4);
    cout << point_1.x_1 << "\t" << point_1.y_1 << endl;
    cout << point_2.x_d << "\t" << point_2.y_d << endl;
    return 0;
}

// мы создаем функцию типа воид как в классе, указание на класс, вызываем че хотим описывать, передаем все то же самое что и в классе и конкретный конструктор присования: берем наши переменные. присваиваем значения внутри класса

void Point::set_point(double x, double y)
{
    x_d = x;
    y_d = y;
}

void Point::set_point(int x, int y)
{
    x_1 = x;
    y_1 = y;
}