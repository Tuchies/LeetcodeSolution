/**
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/**
 * 在78题和90题目的基础上, 增加剪枝操作
 * 具体体现为: 
 *  在递归调用前, 判断当前元素的和, 如果已经大于, 就直接跳出当前循环, 进行下一组
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > res;

int sum(vector<int> ins) {
    if (ins.size() < 1) return 0;
    int sum = 0;
    for (int j = 0; j < ins.size(); j ++)
        sum += ins[j];
    return sum;
}

void backtrack(vector<int> track,int start,vector<int>& candiates, int target) {
    // 判断满足条件
    if (sum(track) == target)
        res.push_back(track);
    else {
        for (int i = start; i < candiates.size();i ++) {
            // 判断是否重复
            if (i > start && candiates[i] == candiates[i-1]) continue;
            // 判断当前数组元素的和
            if (sum(track) > target) continue;
            // 放入元素
            track.push_back(candiates[i]);
            // 递归
            backtrack(track,i+1,candiates,target);
            // 撤销
            track.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> track;
    backtrack(track,0,candidates,target);
    return res;
}

int main() {
    int n, tmp, tar;
    cin >> n >> tar;
    vector<int> list;
    while (n --) {
        scanf("%d",&tmp);
        list.push_back(tmp);
    }
    
    vector<vector<int> > ans = combinationSum2(list,tar);
    for (int i = 0;i < ans.size();i ++) {
        for (int j = 0;j < ans[i].size();j ++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}