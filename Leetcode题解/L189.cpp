/**
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
 * 规定最好原地交换, 不使用额外的空间
 */

/**
 * 解题思路: 参见官方题解: "环状替代"方法
 * 
 * 遍历数组, 从第一个元素a开始, 找出它旋转之后的位置m, 放进去
 * 原来位置m的值使用中间变量保存, 然后寻找m元素旋转后的位置n, 放进去....
 * 以此类推, 直到末尾
 * 
 * 关键点: 确定元素旋转之后的索引位置
 * target_index = (current_index + k) % nums.size()
 */ 

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    if (k % len == 0 || len < 2) 
        return ;
    // 遍历
    int count = 0; // 记录交换的次数, 需要交换len次
    for (int i = 0; count < len; i ++) {
        int curIndex = i; 
        int pre = nums[curIndex];   
        do{
            // 计算目标位置的索引
            int nextIndex = (curIndex + k) % len;
            // 中间变量保存目标位置的值
            int temp = nums[nextIndex];   
            // 将当前元素放到目标位置
            nums[nextIndex] = pre;
            // 将原目标位置的值暂放到当前位置
            pre = temp;
            // 移动当前索引, 
            curIndex = nextIndex;
            count++;
        } while(i != curIndex)  ;     
    }
}

int main() {
    vector<int> list;
    int temp;
    int k;
    cin >> k;
    while(cin >> temp) {
        list.push_back(temp);
    }
    for (int i = 0; i < list.size(); i ++) {
        cout << "the current list: "<< list[i] << endl;
    }
    rotate(list, k);
    for (int i = 0; i < list.size(); i ++) {
        cout << list[i] << endl;
    }
    return 0;
}