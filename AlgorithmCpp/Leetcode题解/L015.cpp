/**
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，* b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */

/**
 * 解题思路: 参见https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/的题解
 * 
 * 遍历排序后数组：
    1. 若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 00，直接返回结果。

    2. 对于重复元素：跳过，避免出现重复解

    3. 令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
        * 当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,RL,R 移到下一位置，寻找新的解
        * 
        * 若和大于 00，说明 nums[R]太大，RR 左移
        * 
        * 若和小于 00，说明 nums[L]太小，LL 右移
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    if (nums.size() < 3) {
        return ans;
    }
    // 排序
    sort(nums.begin(), nums.end());
    for (int j = 0; j < nums.size(); j ++) {
        cout << "排序后的数组: " << nums[j] << endl;
    }
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] > 0) {
            // 之后不可能再有三个元素和为0, 直接返回
            return ans;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            // 跳过重复元素
            continue;
        }
        int left = i+1;
        int right = nums.size()-1;
        while(left < right) {
            if (nums[i] + nums[left] + nums[right] == 0) {
                // 添加结果集
                vector<int> temp = {nums[i], nums[left], nums[right]};
                ans.push_back(temp);
                // 检查重复元素
                while(left < right && nums[left] == nums[left+1])
                    left = left + 1;
                while(left < right && nums[right] == nums[right-1])
                    right = right-1;
                left = left +1;
                right = right -1;
            }
            // 当前和大于0, 就移动右指针
            else if (nums[i] + nums[left] + nums[right] > 0){
                right = right - 1;
            }
            // 当前和小于0, 就移动左指针
            else {
                left = left + 1;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    int temp;
    for (int i = 0; i < n; i ++) {
        cin >> temp;
        list[i] = temp;
        cout << "temp: "<< temp <<endl;
    }
    vector<vector<int> > ans = threeSum(list);
    for (int a = 0; a < ans.size(); a ++) {
        for (int b = 0; b < 3; b ++) {
            cout << ans[a][b] << endl;
        }
    }
    return 0;
}
