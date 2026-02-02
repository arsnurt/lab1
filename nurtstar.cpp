#include <iostream>
using namespace std;

double inputcheck() {
    string s;
    bool check, check2 = 1;
    if (s[0] == '-') check2 = 0;
    while(true)
    {
        check = 1;
        cin >> s;
        if (check2 == 0) s = s.substr(1);
        int digits = 0;
        for (char c : s) {
        
            if (isdigit(c)) digits++;
            else check = 0;
        }
        if (digits > 18) check = 0;
        if (check == 0) cout << "Input error. Please, try again: ";
        else break;    
    }  
    if (check2 == 0) return -stod(s);
    else return stod(s);
}

int main()
{
    double a = inputcheck();
    return 0;
}