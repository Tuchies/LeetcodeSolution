#include<iostream>
#include<vector>
using namespace std;

vector<int> calVector(vector<int>& list1, vector<int>& list2) {
    // 结果集
    vector<int> res;
    // 特判
    if (list1.size() <= 0 || list2.size() <= 0) return res;
    // 双层遍历
    for (int i = 0; i < list1.size(); i ++) {
        for (int j = 0; j < list2.size(); j ++) {
            // 判断相等
            if (list1[i] == list2[j]) {
                res.push_back(list1[i]);
                break;
            }
            
        }
    }
    return res;
}

int main() {
    vector<int> list1;
    vector<int> list2;
    // 测试用例1
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(2);
    list1.push_back(1);
    list2.push_back(2);
    list2.push_back(2);
    // 测试用例2
    // list1.push_back(4);
    // list1.push_back(9);
    // list1.push_back(5);
    // list2.push_back(9);
    // list2.push_back(4);
    // list2.push_back(9);
    // list2.push_back(8);
    // list2.push_back(4);
    vector<int> ans = calVector(list1, list2);
    // 打印结果
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}

/**
 * 给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
*/