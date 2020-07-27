/**
 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/**
 * 思路: 在78题的基础上做剪枝操作
 * 先对原数组进行排序, 在track放入当前元素之前, 判断左右的和前一个元素是否重复
 *  如果重复, 跳过本次循环, 相当于跳过了这个元素
 *  如果没有重复, 照常进行
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > res;

void backtrack(vector<int> track, int start, vector<int>& nums) {
    res.push_back(track); 
    for (int i = start; i < nums.size(); i ++)  {
        // 判重, 减枝
        if (i > start && nums[i] == nums[i-1]) 
            continue;
        track.push_back(nums[i]); // 放入当前元素, 做选择
        backtrack(track,i+1,nums);
        track.pop_back(); // 撤销选择, 恢复状态
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> track;
    sort(nums.begin(),nums.end());
    backtrack(track,0,nums);
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
    
    vector<vector<int> > ans = subsetsWithDup(list);
    for (int i = 0;i < ans.size();i ++) {
        for (int j = 0;j < ans[i].size();j ++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}















