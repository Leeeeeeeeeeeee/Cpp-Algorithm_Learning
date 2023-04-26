#include <iostream>
using namespace std;
/**
 * 编写一个函数，输入一个整数n，返回1！+2！+3！+……+n！的值
*/
//获得某个数的阶乘
int factorial(int num) {
    int fact = 1;
    for(int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
//将阶乘累加
int sum_of_factorials(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of factorials of numbers from 1 to " << n << " is " << sum_of_factorials(n) << endl;
    return 0;
}
