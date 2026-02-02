#include <iostream>
int list(int n) {
    if (n <= 0) {return 0;}
    else {std::cout << n << "\n";}
    return list(n - 1);
}

void arithmetic_sequence(int n, int i = 0){
    if(n<=0){return;}
    std::cout << i << std::endl;
    arithmetic_sequence(n-1, i+5);
}

void repeat(int n){
    if(n<=0){return;}
    std::cout << "1" << std::endl;
    repeat(n-1);
}

void minus_plus(int n, int i = 0){
    if (n==0){return;}
    if(i%2 == 0){std::cout << "1" << std::endl;}
    else{std::cout << "-1" << std::endl;}
    minus_plus(n-1, i+1);
}

void alternating_sequence(int n, int i = 1){
    if(n<=0){return;}
    if(i%2==0){std::cout << "-" << i << std::endl;}
    if(i%2!=0){std::cout << i << std::endl;}
    alternating_sequence(n-1, i+1);
}

void powers_of_two(int n, int i = 1){
    if(n<=0){return;}
    std::cout << i * 2 << std::endl;
    powers_of_two(n-1, i*2);
}

void self_multiplying(int n, int i = 1){
    if(n<=0){return;}
    std::cout << pow(2, i) << std::endl;
    self_multiplying(n-1, i*2);
}

void sequence(int n, int i = 0){
    if(n<=0){return;}
    if(i>3){i=0; std::cout << i << std::endl;}
    else(std::cout << i << std::endl);
    sequence(n-1, i+1);
}

void factorial_seq(int n, int i = 1){
    if(n<=0){return;}
    std::cout << i << "!" << std::endl;
    factorial_seq(n-1, i+2);
}

void power_seq(int n, int i = 0){
    if(n<0){return;}
    if(i==0){std::cout << "1" << std::endl;}
    else if(i==1){std::cout << "a" << std::endl;}
    else(std::cout << "a^" << i << std::endl);
    power_seq(n-1, i+1);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "а)" << std::endl;
    list(n);
    std::cout << "б)" << std::endl;
    arithmetic_sequence(n);
    std::cout << "в)" << std::endl;
    repeat(n);
    std::cout << "г)" << std::endl;
    minus_plus(n);
    std::cout << "д)" << std::endl;
    alternating_sequence(n);
    std::cout << "е)" << std::endl;
    powers_of_two(n);
    std::cout << "ж)" << std::endl;
    self_multiplying(n);
    std::cout << "з)" << std::endl;
    sequence(n);
    std::cout << "и)" << std::endl;
    factorial_seq(n);
    std::cout << "к)" << std::endl;
    power_seq(n);
    return 0;
}