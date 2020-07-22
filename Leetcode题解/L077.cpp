/**
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 */

/**
 * 参考: https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
 * 
 * 回溯法:
 * 
 * 关键在于回溯深度的控制, i=start; i<=n;(此处可以优化)
 *  
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;

// 通过start控制回溯的深度, 每次+1, 直到n
// 通过对vector的传址, 达到栈的效果
void dfs(int n, int k, int start, vector<int> &path) {
    // 达到k, 装进结果数组
    if (path.size() == k) {
        res.push_back(path);
        return;
    }

    for (int i = start; i <= n; ++i) {
        path.push_back(i);
        dfs(n, k, i + 1, path);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    // 特判
    if (n <= 0 || k <= 0 || k > n) {
        return res;
    }

    vector<int> path;
    // 从1开始, 1...n
    dfs(n, k, 1, path);
    return res;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int> > ans = combine(n,k);
    for (int i = 0; i < ans.size(); i ++) {
        for (int j = 0; j < k; j ++) {
            cout << ans[i][j] << endl;
        }
    }
    return 0;
}