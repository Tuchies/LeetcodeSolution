// 自己实现乘方运算

// 注意考虑负数幂的情况

#include<iostream>

using namespace std;

double myPow(double x, int n) {
    long long N = n;
    // 负数情况, 多次 ×分数
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i ; i /= 2) {
        if ((i % 2) == 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
    }
    return ans;
}

int main() {
    double num;
    int n;
    cin >> num >> n;
    cout << myPow(num, n);
    return 0;
}