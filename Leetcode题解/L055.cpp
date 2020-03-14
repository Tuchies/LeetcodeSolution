// 动态规划问题：依然是倒着分析，首先判断倒数第二个元素是否可以到达末尾元素；若可以，往前递推；直到判断第一个元素是否可以跳到第二个元素

// 转移方程：定义dp[i]表示数组下标为i的元素能够被到达，如果最终dp[vetor.size()-1]为true，则表示可以到达最后一个元素；初始化dp[0]为true，能够达到i节点的条件为：i之前的某个节点j为true，且结点j的值大于等于i节点的值

#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() < 1) return false;
    bool *dp = new bool[nums.size()];
    dp[0] = true;

    // 双指针遍历，判断从前面的节点是否可以到达后面节点
    // 只要能到达，就跳出内层循环
    for (int i = 1; i < nums.size(); i ++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && nums[j] + j >= i) {
                dp[i] = true;
                break;
            } else {
                dp[i] = false;
            }
        }
    }
    return dp[nums.size() - 1];
    delete dp;
}

int main() {
    vector<int> in;
    in.push_back(3);
    in.push_back(2);
    in.push_back(1);
    in.push_back(0);
    in.push_back(4);

    cout << canJump(in) << endl;
    return 0;
}