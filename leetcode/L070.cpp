// 动态规划：第 iii 阶可以由以下两种方法得到：在第 (i−1)(i-1)(i−1) 阶后向上爬一阶。在第 (i−2)(i-2)(i−2) 阶后向上爬 222 阶。
// 所以到达第 iii 阶的方法总数就是到第 (i−1)(i-1)(i−1) 阶和第 (i−2)(i-2)(i−2) 阶的方法数之和。

#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    const int l = n;
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i ++) {
        dp[i] = dp[i -1] + dp[i - 2];
    }
    return dp[n];
    delete dp;
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n);
    
}