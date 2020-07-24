/*
小易有一个体积巨大的货物，具体来说，是个在二维平面上占地的货物。
小易有一个的广场，想把货物放在这个广场上。不幸的是，广场上已经有了一些障碍物，障碍物所在的格子不能放置你的货物。小易现在想知道能否成功地放置货物。

输入描述:
第一行数字t，表示有t组数据。
对于每一组数据，第一行三个数字n,m,k，表示广场的大小和障碍物的个数。接下来k行，每行两个数x,y，表示一个障碍物的坐标。
接下来一行两个数c,d，表示货物的大小。
，

输出描述:
对于每组数据，输出"YES"或者"NO"表示货物是否可以被放置。

输入例子1:
2
3 3 1
1 1
2 2
3 3 1  
2 2  
2 2  

输出例子1:
YES
NO
*/

/**
 * 思路: 
 *  1. 遍历广场的每一个单元格, 从当前坐标开始进行判断
 *  2. 如果从当前坐标开始, 往右往下均能遍历完货物的尺寸(也即当前横纵坐标+货物的长宽尺寸 没有超出广场边界), 则表示可以放下
 *  3. 如果从当前坐标开始, 没有遍历完货物的尺寸, 就遇到了障碍物, 则需要把这中间的所有单元格都视为有障碍物的 (因为从这中间的任意点开始遍历货物尺寸, 都会遇到这个障碍物)
 */

#include <vector>
#include <iostream>
 
using namespace std;
 
int t;
int n, m, k;
 
bool judge(vector<vector<bool>> &v, int ni, int nj, int c, int d) {
    // c是货物的横向尺寸, ni是当前在广场的横向坐标
    for (int i = 0; i < c; i++) {
        // 如果当前坐标 + (<=的)货物尺寸 超出了广场尺寸
        if (ni + i >= n) 
            return false;
        for (int j = 0; j < d; j++) {
        // 同理, 如果当前纵坐标 + (<=的)货物竖尺寸 超出了广场尺寸
            if (nj + j >= m) 
                return false;
            // 在横向和纵向遍历货物尺寸的过程中, 只要是没有障碍, 就继续, 直到遍历完成整个货物尺寸
            // 如果遇到了障碍物 则起点和障碍之内(遍历过)的点全部不可能为结果的起点 (因为遍历过的点往右或往下会有障碍)
            if (v[ni + i][nj + j]) {
                
                // 因此全部置为障碍
                for (int p = 0; p <= i; p++) {
                    for (int k = 0; k <= j; k++) {
                        v[ni + p][nj + k] = true;
                    }
                }
                return false;
            }
        }
    }
    // 如果能横向纵向遍历完货物的尺寸 就表示可以放下
    return true;
}
 
int main() {
 
    cin >> t; // 测试个数
     
    while (t--) {
        cin >> n >> m >> k;
        // 初始化n*m的二维数组表示广场, 每个单元格初始化为false, 表示没有障碍物
        vector<vector<bool>> v(n, vector<bool>(m, false));
        // 根据输入, 将有障碍物的单元格初始化为true
        while (k--) {
            int a, b;
            cin >> a >> b;
            v[a - 1][b - 1] = true;
        }
        // 货物大小
        int c, d;
        cin >> c >> d;
         
        bool flag = false;
        // 遍历广场每一个单元格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 判断当前坐标往右往下能否放得下货物
                if (!v[i][j] && judge(v, i, j, c, d)) {
                    flag = true;
                    break;
                }
            }
            if (flag) 
                break;
        }
        // 对本组测试数据进行输出
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
     
    return 0;
}