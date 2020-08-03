/**
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int> > dp(m+1,vector<int>(n+1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 两个串字符相等
            if (text1[i] == text2[j]) {
                // 去找它们前面各退一格的值加1即可
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } 
            // 如果不相等
            else {
                //要么是text1往前退一格，要么是text2往前退一格，两个的最大值
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {

}