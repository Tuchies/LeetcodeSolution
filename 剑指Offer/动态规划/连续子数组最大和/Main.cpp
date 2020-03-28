// 连续字数组最大和问题，经典的动态规划问题，即比较当前数，与当前数+已累计的和得到的和，之间的大小关系
// 设dp[i]存放的是数组下标为i时积累的最大和，dp[i] = MAX{dp[i-1], dp[i-1]+int[i]}， 初始化dp[0]=int[0]，最终结果是dp[i]数组中的最大元素

#include<iostream>
#include<vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    if(array.size() < 1) return 0;
    if(array.size() == 1) return array[0];
    int *dp = new int[array.size()];
    dp[0] = array[0];
    int max_sum = array[0];
    for(int i = 1; i < array.size(); i ++) {
        dp[i] = max(array[i], dp[i-1]+array[i]);
        if(max_sum < dp[i]){
            max_sum = dp[i];
        }
    }
    return max_sum;
    delete dp;
}

int main() {
    vector<int> in;
    in.push_back(6);
    in.push_back(-3);
    in.push_back(-2);
    in.push_back(7);
    in.push_back(-15);
    in.push_back(1);
    cout << FindGreatestSumOfSubArray(in) << endl;
    return 0;
}