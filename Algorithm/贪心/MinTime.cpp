// 贪心算法的经典问题：
// 一组人排队等待业务处理，每个人的处理时间记作Ti，问如何安排使得总时间最短？例如：有三人处理时间分别为3，2，5，最佳的排列顺序应该为2，3，5，总时间total = 2 + 5 +10


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minTime(vector<int>& in) {
    sort(in.begin(), in.end()); //升序排列
    int sum = 0;
    // 设wait[i]表示第（i+1)个人需要等待前一个的时间
    int *wait = new int[in.size()]; 
    wait[0] = 0; // 第一个人不用等
    sum += wait[0] + in[0];  // 初始化
    for(int i = 1; i < in.size(); i ++) {
        // 更新等待时间
        wait[i] = wait[i-1] + in[i-1]; 
        // 当前总花费是：当前人的时间 + 之前的等待时间
        sum += in[i] + wait[i]; 
    }
    return sum;
}

int main() {
    vector<int> i;
    i.push_back(2);
    i.push_back(5);
    i.push_back(3);
    i.push_back(3);
    cout << minTime(i) << endl;
    return 0;
}