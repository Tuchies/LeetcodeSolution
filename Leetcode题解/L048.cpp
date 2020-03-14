// 常规思路：先完成矩阵的转置，然后对于转置后的矩阵的每一行，进行反转

#include<iostream>
#include<vector>

using namespace std;

void rotate(vector< vector<int> >& martix) {
    int len = martix.size();

    // 转置矩阵
    for(int i = 0; i < len; i ++) {
        for (int j = i; j < len; j ++) {
            int temp = martix[j][i];
            martix[j][i] = martix[i][j];
            martix[i][j] = temp;
        }
    }

    // 对于每一行进行反转
    for(int i = 0; i < len; i++) {//控制行
        for(int j = 0; j < len/2; j++) {
            int temp = martix[i][j];
            martix[i][j] = martix[i][len-j-1];
            martix[i][len-j-1] = temp;
        }
    }
}

int main() {
    vector<vector<int> > m;
    vector<int> m1;
    vector<int> m2;
    vector<int> m3;
    m1.push_back(1);
    m1.push_back(2);
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
    rotate(m);
    for (int i = 0; i < m.size(); i ++) {
        for (int j = 0; j < m[1].size(); j ++ ){
            cout << m[i][j] << endl;
        }
    }
    return 0;
}