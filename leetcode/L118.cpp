//初始化n行二位数组，遍历每行每个元素
// 若是边界，则赋值为1；否则赋值为前一行相邻两元素和
// 关键在于边界元素,和上一行两加数元素的下标规律

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > list(numRows);
    if (numRows == 0) return list;
    for (int i = 0; i < numRows; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0 || j == i) {
                list[i].push_back(1);
            } else {
                list[i].push_back(list[i-1][j-1] + list[i-1][j]);
            }
        }
    }
    return list;
}

int main() {
    int n; 
    cin >> n;
    vector<vector<int> > list = generate(n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= i ; j  ++){
            cout << list[i][j] <<endl;
        }
    }
}