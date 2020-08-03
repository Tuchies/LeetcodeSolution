/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
*/

/**
 * 参考: labuladong(公众号同名)用户的模板解法
 * 
 * 模板: 使用多维数组表示当前天的状态: 如 dp[2][1][0]表示这是第2天, 允许交易一次, 当前没有持有股票; dp[3][3][1]表示这是第3天, 允许交易3次, 当前持有股票
 * 
 * 状态转移方程: 
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])

    解释：今天我没有持有股票，有两种可能：
        要么是我昨天就没有持有，然后今天选择 rest不操作，所以我今天还是没有持有；
        要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

    解释：今天我持有着股票，有两种可能：
        要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
        要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。

 * 初始化base case:
 *  dp[-1][k][0] = 0
    解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0

    dp[-1][k][1] = -infinity
    解释：还没开始的时候，是不可能持有股票的，⽤负⽆穷表⽰这种不可能。

    dp[i][0][0] = 0
    解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0

    dp[i][0][1] = -infinity 
    解释：不允许交易的情况下，是不可能持有股票的，⽤负⽆穷表⽰这种不可能。       
 */

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int> > dp(n+1, vector<int>(2));
    dp[-1][0] = 0, dp[-1][1] = INT_MIN;
    // 处理i==0的情况
    for (int i = 0; i < n; i++) {
        if (i - 1 == -1) {
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], -prices[i]);
    }
    return dp[n-1][0];
}


int main() {
    vector<int> list;
    list.push_back(2);
    list.push_back(4);
    list.push_back(3);
    cout << maxProfit(list);
    return 0;
}