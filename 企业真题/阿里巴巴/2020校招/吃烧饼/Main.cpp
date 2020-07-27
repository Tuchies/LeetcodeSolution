/*
吃烧饼，有n个盘子和每个盘子的烧饼数，每次选一个x(x <= n)，吃掉第1~x号盘子的一个烧饼，若第1~x号盘子中有空盘，则不能选择这个x。 假设胃无限大，问最多可以吃多少烧饼。

样例：
输入
3
2 1 3
输出：
4 
*/

/**
 * 题目翻译: 
 * 根据给定的数组, 选一个盘子x, 在1至x的盘子中间循环吃, 直到遇到一个空盘子; 问: 选哪个盘子会使得吃到的烧饼最多, 打印最多是多少?
 * 
 * 思路: 
 * 以样例为例: 对于盘子1, 最多可吃2; 对于盘子2, 最多可吃2+2(因为再循环之后1就会变成空盘, 所以盘中2可以吃到的数量以前遍的盘子的最小值为准)
 * 
 * 总结: 对于盘子i, 它可以迟到的数量是它之前盘子的最小值决定的; 因此, 在读取输入的时候, 维护一个最小值, 最终结果就是所有盘子的最小值之和
 */ 

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n; // n个盘子
    vector<int> nums(n, 0);
    int min_num = INT_MAX;
    long long ans = 0;

    for(int i = 0; i < n; i++){
        scanf("%d",&nums[i]); // 盘中的烧饼数
        // 维持最小值
        if (nums[i] < min_num){
            min_num = nums[i];
        }
        ans += min_num;
    }
    printf("%d\n",ans);
    return 0;
}