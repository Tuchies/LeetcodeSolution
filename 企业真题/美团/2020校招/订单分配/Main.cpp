/**
打车派单场景, 假定有N个订单， 待分配给N个司机。每个订单在匹配司机前，会对候选司机进行打分，打分的结果保存在N*N的矩阵A， 其中Aij 代表订单i司机j匹配的分值。

假定每个订单只能派给一位司机，司机只能分配到一个订单。求最终的派单结果，使得匹配的订单和司机的分值累加起来最大，并且所有订单得到分配。

输入描述:
第一行包含一个整数N，2≤N≤10。

第二行至第N+1行包含N*N的矩阵。

输出描述:
输出分值累加结果和匹配列表，结果四舍五入保留小数点后两位
（注意如果有多组派单方式得到的结果相同，则有限为编号小的司机分配编号小的订单，比如：司机1得到1号单，司机2得到2号单，就比司机1得到2号单，司机2得到1号单要好）
示例1
输入
3
1.08 1.25 1.5
1.5 1.35  1.75
1.22 1.48 2.5
输出
5.25
1 2
2 1
3 3
说明
第一行代表得到的最大分值累加结果5.25，四舍五入保留两位小数；

第二行至第四行代表匹配的结果[i j],其中i按行递增：

订单1被派给司机2，订单2被派给司机1，订单3被派给司机3。使得A12+ A21+ A33= 1.25 + 1.5 + 2.5 = 5.25在所有的组合中最大。
*/

/**
 * 暂时看不懂
 */
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
 
void backTrack(vector<vector<double>>& num,
    vector<bool>&used, vector<int>& pre,
    vector<int>& cur,
    double curProfit, double& preProfit, int n, int pos) {

    //如果pos == n 说明行数已经达到n行，所有的行都已经选完，是一种结果
    if (pos == n) {
        //全局找最大，判断是否出现更优解
        if (curProfit > preProfit) {
            //更新当前最大的和
            preProfit = curProfit;
            //数组赋值,将这个最优解的数组赋值给pre，最后用来输出
            pre = cur; 
        }
        return;
    }
     
    //枚举第pos行的每一列
    for (int i = 0; i < n; i++) {
        //改行必须在之前没有被选择使用过，必须满足题意
        if (!used[i])  // 标记第 i列，下一次第i列就不能选择了
        {
            //代表本次选择pos行的i列元素，进行标记本次递归的选择位置
            //因为可能出现本次选择是最优的情况，所以需要保存
            cur[pos] = i;  // 记录每一个 pos行对应的列数i，下面的就是回溯过程
             
            //代表当前的评分和加上本次的选择
            //同理和cur一样都要保存
            curProfit += num[pos][i];
             
            //代表着第i例被使用过，下次不能在选择第i列
            used[i] = true;
            backTrack(num,used,pre,cur, curProfit, preProfit, n, pos + 1);
            //撤销选择
            curProfit -= num[pos][i];
            //撤销标记
            used[i] = false;
        }
    }
}
 
int main() {
    int n;
    cin >> n;
    // 填充二维数组
    vector<vector<double>> vvd(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vvd[i][j];
        }
    }
        
    vector<int> pre(n); //  记录最优解的每个值 所在的 列数
    vector<int> cur(n); //  列数加入数组
    vector<bool> used(n); // 标记数组， 因为一列只能选择一个
    double preProfit = INT_MIN; // 全局的最大值
    double curProfit = 0.0; // 当前的最大值
    int pos = 0;  // pos就是行数，pos到达一行，就选y值就可以了
    backTrack(vvd, used, pre, cur, 
        curProfit, preProfit, n, pos); 

    //打印结果
    printf("%4.2f\n",preProfit);
    for (int i = 0; i < pre.size(); i++) {
        cout << i + 1 << " " << pre[i] + 1 << endl;
    }
    return 0;
}