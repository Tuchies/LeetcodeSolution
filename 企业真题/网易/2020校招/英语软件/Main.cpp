/**
 * 
小易是班级的英语课代表, 他开发了一款软件开处理他的工作。
小易的软件有一个神奇的功能，能够通过一个百分数来反应你的成绩在班上的位置。“成绩超过班级 ...% 的同学”。

设这个百分数为 p，考了 s 分，则可以通过以下式子计算得出 p：
p = ( 分数不超过 s 的人数 - 1) / 班级总人数 

突然一天的英语考试之后，软件突然罢工了，这可忙坏了小易。成绩输入这些对于字写得又快又好的小易当然没有问题，但是计算这些百分数……这庞大的数据量吓坏了他。
于是他来找到你，希望他编一个程序模拟这个软件：给出班级人数 n，以及每个人的成绩，请求出某几位同学的百分数。

输入描述:
第一行一个整数 n，表示班级人数。 
第二行共 n 个自然数，第 i 个数表示第 i 位同学的成绩 a_i。 
第三行一个整数 q，表示询问的次数。 
接下来 q 行，每行一个数 x，表示询问第 x 位同学的百分数。


输出描述:
输出应有 q 行，每行一个百分数，对应每一次的询问。

为了方便，不需要输出百分号，只需要输出百分号前的数字即可。四舍五入保留六位小数即可。

输入例子1:
3
100 98 87
3
1
2
3

输出例子1:
66.666667
33.333333
0.000000
*/

#include<iostream>
#include<vector>
using namespace std;

double getNumber(vector<double> list, double score) {
    if (list.size() < 1)
        return 0;
    double count = -1.0; // 遍历的时候包括了自己
    for (int j = 0; j < list.size(); j ++) {
        if (list[j] <= score)
            count ++;
    }
    return count;
}

int main() {
    int n, ask, ask_number;
    cin >> n;
    vector<double> list(n+1);
    list[0] = 0; // 没有第0位同学
    for (int i = 1; i <= n; i ++) {
        cin >> list[i];
    }
    // 处理问询
    cin >> ask;
    while (ask --) {
        cin >> ask_number;
        double score = list[ask_number];
        // p = ( 分数不超过 s 的人数 - 1) / 班级总人数
        // 求分数不超过 score的人数; <=
        double ans = (getNumber(list,score)-1) / n;
        printf("%.6f\r\n", ans*100);
    }
    return 0;
}
