// 思路：遍历1~n，使得每个数字i都做一次根节点来构建二叉搜索树，其中1~(i-1)为左子树，其余为右子树；对于已经分好的序列，可以用同样的方法来构建子树，目标问题被分为了结构相似、规模更小的子问题，符合动态规划问题性质

// 难点是：从上述思路来看，得到的结果是根节点为i的二叉搜索树个数，而题目所求是长度为n可构建的二叉搜索树个数，因此，需要定义两个函数，dp[i][n]表示以i为根节点可得到的个数，s(n)表示长度为n的序列可得到的树个数，这也是结果所求

// 状态方程：举例：有序列1~7，现以3为根节点构建二叉树，那么要从1~2中选取节点构建左子树，从4~7中构建右子树；同时，1~2可以构建的子树个数可以表示为s(2),4~7可以构建的子树个数为s(4),则有dp[i][n] = s(n-1)*s(n-i)

#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n) {
    int *dp = new int[n+1]; // 用于存放当前节点可构建的二叉树个数
    int *sum = new int[n+1]; // 考虑到数组下标问题
    sum[0] = 1;
    sum[1] = 1;
    sum[2] = 2;
    for (int i = 3; i <= n; i ++) {// 遍历序列
        for(int j = 1; j <= i; j ++) {// 当前进行的节点
            dp[j] = sum[j-1]*sum[i-j];
            sum[i] += dp[j];
        }
    }
    return sum[n];
    delete dp;
    delete sum;
}

int main() {
    int x;
    cin >> x;
    cout << numTrees(x) << endl;
    return 0;
} 