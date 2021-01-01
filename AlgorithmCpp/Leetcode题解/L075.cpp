// 常规思路：因为使用数字表示颜色，故可以直接排序当前数组

#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) {
   // 快排
   // TODO
}

int main() {
    vector<int> n;
    n.push_back(0);
    n.push_back(2);
    n.push_back(2);
    n.push_back(1);
    n.push_back(0);
    sortColors(n);
    for(int i = 0; i < n.size(); i ++) {
        cout << n[i] << endl;
    }
}