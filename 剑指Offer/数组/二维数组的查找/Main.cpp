/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/*
思路:
先确定列, 和每一列的首位两元素比较, 确定范围
*/

#include<iostream>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    // 边界检查
    int m = array.size(), n = array[0].size();
    if (m < 1 || n < 1) {
        return false;
    }
    bool ans;
    // 确定行
    int rowIndex = -1;
    for (int i = 0; i < m; i ++) {
        if (array[i][0] == target || array[i][n-1] == target){
            return true;
        }
        if (array[i][0] < target && array[i][n-1] > target){
            rowIndex = i;
        } 
        if (rowIndex == -1)
            continue;
        // 遍历这一行
        for(int j = 0; j < n; j ++) {
            if (array[rowIndex][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int target, m, n;
    cin >> target >> m >> n;
    vector<vector<int> > list(m, vector<int> (n));
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++) {
            cin >> list[i][j];
        }
    }
    
    cout << Find(target, list) << endl;
    return 0;
} 