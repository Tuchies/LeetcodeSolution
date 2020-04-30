/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
思路: 
直接模拟路径, 
    向右走的情况一定是在: 顶层, 未遍历的数据
    向下走的情况一定是:   最右层, 未遍历的数据
    向左走的情况一定是:   底层, 未遍历的数据
    向上走的情况一定是:   最左层, 未遍历的数据

以123, 456, 789为例: 
    从1出发, 向右走, 当y触碰到最右边时, 开始向下
    从3往下走, 当x坐标触碰到最底层时, 开始向左
    从9向左走, 当Y坐标触碰到最左边时, 开始向上
    重点来啦: 当从7向上走, 到达当前的次顶层时, 即到达4时, 更改"顶层","底层","最左边","最右边"的范围, 集中向内缩小
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> ans;
    if(matrix.empty())
        return ans;    
    int x, y, len = matrix[0].size()*matrix.size();
    // 上下左右四边
    int rightEdge = matrix[0].size()-1, downEdge = matrix.size()-1, leftEdge = 0, upEdge = 0;
    
    for(x=0, y=0; len > 0; len --){
        // 初始化
        ans.push_back(matrix[x][y]);
        // 在顶层向右走
        if(x == upEdge){
            if(y < rightEdge)
                y++;
            else if(y==rightEdge)
                x++;
        continue;
        }
        // 在右层向下走
        if(y == rightEdge){
            if(x < downEdge)
                x++;
            else if(x == downEdge)
                y--;
        continue;
        }
        // 在顶层向左走
        if(x == downEdge){
            if(y > leftEdge)
                y--;
            else if(y == leftEdge)
                x--;
        continue;
        }
        // 在左层向上走
        if(y == leftEdge){
            if(x > upEdge+1)
                x--;
            // 到达当前次顶层, 集中缩小四边范围
            else if(x == upEdge+1){
                y++;
                leftEdge++;
                upEdge++;
                rightEdge--;
                downEdge--;
                }
        continue;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > list(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> list[i][j];
        }
    }
    cout << printMatrix(list)[n*n - 1] << endl;
    return 0;
}