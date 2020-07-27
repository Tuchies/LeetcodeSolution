/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/**
 * 参考: https://leetcode-cn.com/problems/subsets/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-t/
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    // 保证开始索引不越界
    for (int i = start; i < nums.size(); i++) {
        // 做选择
        track.push_back(nums[i]);
        // 回溯, 递归: 更新开始索引
        backtrack(nums, i + 1, track);
        // 撤销选择, 移除track中的最后一个元素
        track.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    // 记录走过的路径
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

int main() {
    int n, tmp;
    cin >> n;
    vector<int> list;
    while (n --) {
        scanf("%d",&tmp);
        list.push_back(tmp);
    }
    
    vector<vector<int> > ans = subsets(list);
    for (int i = 0;i < ans.size();i ++) {
        for (int j = 0;j < ans[i].size();j ++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}