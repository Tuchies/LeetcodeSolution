// 当前行的数据只和上一行有关，则开辟一个数组记录上一行数据
// 从第一行开始，对每一行元素赋值，当前行元素处理完后，就赋值给上一行数据，当前行清空


#include<iostream>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> cur;
    vector<int> pre;
    for (int i = 0; i < rowIndex + 1; i++) {
        cur.clear();
        for (int j = 0; j <=i; j ++) {
            if (i==j || j==0) {
                cur.push_back(1);
            } else {
                cur.push_back(pre[j] + pre[j - 1]);
            }
        }
        pre = cur;
    }
    return cur;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> list = getRow(n);
    for (int i = 0; i < list.size(); i ++) {
        cout << list[i] << " ";
    }
}