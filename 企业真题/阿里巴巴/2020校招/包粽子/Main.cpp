/*

包粽子, 四个数n, m, c0, d0, 一共n 克面粉， m种馅料
然后m行,每行四个数ai, bi, ci, di, 表示一共多少克该种馅料
每个粽子包法, bi克第i种馅料 + ci 克面粉, 收益di, 或者 c0 克面粉, 不包馅料, 收益d0

求最大收益
*/

/**
 * 暂时没看懂
 */ 

#include<iostream>
#include<vector>
using namespace std; 

const int N = 1010;
int n, m, c0, d0;
int a, b, c, d;
 
struct Node {
    int v, w;
};
 
int dp[N];
 
int main() {
    // 给dp数组填充0
    fill(dp, dp + N, 0);
    vector<Node> ns;
    scanf("%d%d%d%d", &n, &m, &c0, &d0);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int cnt = a / b, k = 1;
        while (cnt) {
            if (cnt >= k) {
                ns.push_back(Node{k * c, k * d});
                cnt -= k;
                k *= 2;
            } else {
                ns.push_back(Node{cnt * c, cnt * d});
                cnt = 0;
            }
        }
    }
    for (int i = 0; i < ns.size() + 1; ++i) {
        if (i == ns.size()) {
            for (int j = c0; j <= n; ++j)
                dp[j] = max(dp[j], dp[j - c0] + d0);
        } else {
            for (int j = n; j >= ns[i].v; --j)
                dp[j] = max(dp[j], dp[j - ns[i].v] + ns[i].w);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}