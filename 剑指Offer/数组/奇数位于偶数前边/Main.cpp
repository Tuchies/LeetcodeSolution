/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
思路:
遍历数组, 找到偶数, 剔除偶数, 从尾部插入当前数组
*/

#include<iostream>
#include<vector>
using namespace std;

void reOrderArray(vector<int> &array) {
    // 边界判断
    if (array.size() < 2) {
        return ;
    }
    int len = array.size();
    vector<int> :: iterator it = array.begin();
    for (int i = 0; i < len; i ++) {
        if (*it % 2 == 0) {
            int temp = *it;
            // 移除元素, it自动指向下一位, 不++
            it = array.erase(it);
            // 尾插
            array.push_back(temp);
        } else {
            it ++;
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i ++) {
        cin >> list[i];
    }
    reOrderArray(list);
    for (int i = 0; i < n; i ++) {
        cout << list[i] << endl;
    }
    return 0;
}