// 异或解法:
// 相同的两个数字, 异或运算结果为0, 0^任意数 = 任意数

#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = nums[0];
    if (nums.size() > 1) {
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
    }
    return ans;
}

int main() {
    vector<int> list;
    int in;
    while(cin >> in) {
        list.push_back(in);
        //cout << in << endl;
    }
    cout << singleNumber(list);
    return 0;
}