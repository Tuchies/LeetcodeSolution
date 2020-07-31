/**
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/**
 * 回溯: 每次遍历数组, 从中选取元素放入"路径"数组
 * 
 * 剪枝: 每次放入之前, 查看当前"路径"数组中是否有重复的元素
 * 
 * 结束: "路径"数组.size == 给定数组.size
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    void backtrack(vector<int>& track, vector<int>& nums);
    vector<vector<int> > res;
    vector<vector<int>> permute(vector<int>& nums) {
        // 路径数组
        vector<int> track;
        backtrack(track, nums);
        return res;
    }

    void backtrack(vector<int>& track, vector<int>& nums) {
        // 判断
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        // 遍历
        for (int i = 0; i < nums.size(); i ++) {
            // 剪枝,取消重复
            // 如果记录的路径中,已经含有了当前元素, 就跳过本次
            if (find(track.begin(),track.end(),nums[i]) != track.end()) continue;
            // 放入选择
            track.push_back(nums[i]);
            // 递归
            backtrack(track, nums);
            // 撤销 选择
            track.pop_back();
        }
    }

int main() {
    int n;
    scanf("%d",&n);
    vector<int> list;
    for(int i = 0; i < n; i ++) {
        scanf("%d",&list[i]);
    }
    vector<vector<int>> r = permute(list);
    for(int j = 0; j < r.size(); j ++) {
        for(int i = 0; i < r[0].size(); i ++) {
            printf("%d",r[j][i]);
            printf("\n");
        }        
    }
    return 0;
}