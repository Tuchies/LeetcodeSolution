// 常规思路：遍历矩阵，遇到元素0，使用Set记下其xy坐标（可防止重复），将对应行列置为0

#include<iostream>
#include<vector>
#include<set>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> row, col;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }

    //再次遍历，如果set中有对应下标，就置为0
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (row.count(i) || col.count(j)) {
                matrix[i][j] = 0;
            }
        }
    }
    
}

int main() {
    vector<vector<int> > m;
    vector<int> m1;
    vector<int> m2;
    vector<int> m3;
    m1.push_back(1);
    m1.push_back(0);
    m1.push_back(3);
    m2.push_back(4);
    m2.push_back(5);
    m2.push_back(6);
    m3.push_back(7);
    m3.push_back(8);
    m3.push_back(9);
    m.push_back(m1);
    m.push_back(m2);
    m.push_back(m3);
    setZeroes(m);
    for (int i = 0; i < m.size(); i ++) {
        for (int j = 0; j < m[1].size(); j ++ ){
            cout << m[i][j] << endl;
        }
    }
    return 0;
}