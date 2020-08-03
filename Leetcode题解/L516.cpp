#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.size();
    // 对于i>j的情况, 不会出现子序列 , 所以所有应该初始化0
    vector<vector<int>> dp(n, vector<int>(n,0));
    // 而对于i<=j的情况, 初始化1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    // 反着遍历保证正确的状态转移
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // 状态转移方程
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    // 整个 s 的最长回文子串长度
    return dp[0][n - 1];
}

int main() {
    string s = "bbbab";
    cout << longestPalindromeSubseq(s);
    return 0;
}