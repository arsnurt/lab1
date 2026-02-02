#include <iostream>

using namespace std;

bool isdivisible(int num) {
    if (num == 0) return false;
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0) {return false;}
        if (original % digit != 0) {return false;}
        num /= 10;
    }
    return true;
}

void task2()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(isdivisible(i)){
            cout << i << endl;
        }
    }
}
int main() {
    task2();
}