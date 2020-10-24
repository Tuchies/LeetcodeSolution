// 动态规划问题：题目中网格为MXN规格，目标在（M-1,N-1);目标的上一种状态有两种情况：（M-2，N-1）和（M-1，N-2）；以此类推，可将该问题分解为若干个规模更小、结构相似的子问题，且子问题的解会被多次调用
// 推导方程：设dp[X,Y]为到达点(X-1,Y-1)的路径总数，则dp[X,Y] = dp[X-1,Y] + dp[X,Y-1]

// 本题需要注意：先初始化第一行和第一列的数据，然后再遍历整个网格

#include<iostream>
#include<vector>

using namespace std;

int uniquePaths(int m, int n) {
    vector< vector <int> > dp(m, vector<int> (n));
    for (int i = 0; i < m; i ++) dp[i][0] = 1;
    for (int i = 0; i < n; i ++) dp[0][i] = 1;
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j -  1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m,n) << endl;
    return 0;
}