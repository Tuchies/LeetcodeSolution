// 题目要求输出斐波那契数列数列的第N项,题目要求从第0项开始
// 一个典型的动态规划问题，设dp[i]放的是第i项的值，dp[0]=0,dp[1]=1,dp[2]=1,...dp[i]=dp[i-1]+dp[i-2]，最终返回dp[n]

#include<iostream>

using namespace std;

int Fibonacci(int n) {
    if (n < 1) return 0;
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    delete dp;
}

int main() {
    int in;
    cin >> in;
    cout << Fibonacci(in) << endl;
    return 0;
}