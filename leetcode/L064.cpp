// 要求在 m * n网格中，从左上角至右下角，使得经过的路径权值和最小
// 同样是个动态规划问题，在网格点G(M,N),有两种结果和（排除边界情况）：一是：(M-1,N)+(M,N);二是：(M,N-1)+(M,N);那么只需要选取两者中的min即可

// 状态方程：首先初始化起点和第一行第一列边界情况，设dp[i][j]为起点到点(i-1,j-1)的最短路径和，则有：dp[i][j] = min{dp[i-1][j] + g[i][j], dp[i][j-1] + g[i][j]}

#include<iostream>
#include<vector>

using namespace std;

int minPathSum(vector< vector<int> >& grid) {
    // 根据本题情况，不需要再定义dp数组来存储结果，直接在原数组中存储即可
    for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[0].size(); j ++) { //遍历网格
            if(i == 0 && j == 0) continue;
            else if(i == 0) { // 第一行
                grid[i][j] = grid[i][j-1] + grid[i][j];
            } 
            else if (j == 0) {// 第一列
                grid[i][j] = grid[i-1][j] + grid[i][j];
            }
            // 转移方程
            else grid[i][j] = min(grid[i][j] + grid[i-1][j], grid[i][j] + grid[i][j-1]);
        }
    }
    return grid[grid.size()-1][grid[0].size()-1];
}

int main() {
    vector<vector <int> >g;
    // test case
    vector<int> g1;
    vector<int> g2;
    vector<int> g3;
    g1.push_back(1);
    g1.push_back(3);
    g1.push_back(1);
    g2.push_back(1);
    g2.push_back(5);
    g2.push_back(1);
    g3.push_back(4);
    g3.push_back(2);
    g3.push_back(1);
    g.push_back(g1);
    g.push_back(g2);
    g.push_back(g3);
    cout << minPathSum(g) << endl;
    return 0;
}