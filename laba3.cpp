#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int task1(int N, int x) {
    int sum = 0;
    for(int i = 1; i <= N-2; i++){sum += pow(i - x, 2.0);}
    return sum;
}

/* int task1_1(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        int product = 1;
        for (int j = i; j <= N-1; j++){product *= (i - j);}
        if (i > N-1) {sum += 1;} 
        else {sum += product;}
    }
    return sum;
} */

int task1_1(int N) {return 1;}

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
    cout << "Find all positive integers that do not exceed a given number N and are divisible by each of their digits." << endl;
    cout << "Please input N: ";
    int n; cin >> n;
    for(int i = 1; i <= n; i++){if(isdivisible(i)){cout << i << endl;}}
}

void task2_1(int num){
    string str = to_string(abs(num));
    int length = str.length();
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    int result = stoi(str);
    cout << result << endl;
}

int main() {
    // t1
    cout << "if x < 0: y = Σ ( i = 1..n-2 ) (i - x)^2" << endl;
    cout << "if x >= 0: y = Σ ( i = 0..n ) Π ( j = i..n-1 ) (i - j)" << endl;
    int x, N;
    cout << "N: ";
    cin >> N;
    cout << "X: ";
    cin >> x;
    if(x >= 0){cout << task1(N, x) << endl;} 
    else {cout << task1_1(N) << endl;}

    //t2
    task2();

    //t3
    cout << "Arrange the digits of the integer in ascending order and form a new integer from them." << endl;
    int num; cin >> num;
    task2_1(num);
    return 0;
}