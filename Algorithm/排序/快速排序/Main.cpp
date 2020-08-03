// 快速排序
// 思路: 从数组中找一个基准数(pivot), 一次遍历, 将小于该基准的放在它前头, 否则放在后头; 递归地对分开的两个子序列使用同样的方法排序

/***
详细步骤: 
1.初始状态, 指针low和high分别指向数组两头
2.先以第一个元素为基准数(挖坑), 从high往前找一个小于基准数的(填那个坑)
3.从后往前找到的那个元素用于填坑了, 形成新坑, 需要从low++ 从前往后找一个大于基准数的(去填后边的新坑)
4.直到 low == high, 把基准数填到 in[low]中
*/

#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& list, int low, int high){
    int i = low, j = high;
    int pivot;
    if(i < j){
        // 基准数取数组首元素
        pivot = list[i];
        // 满足 i==j, 才能将数组分为两部分
        while (i != j) {
            // 从后往前找小于基准数的
            while(j > i && list[j] >= pivot)-- j;
            // 放在之前的空位上
            list[i] = list[j];
            // 从前往后找大于基准数的
            while(i < j && list[i] <= pivot)++ i;
            // 放在之前的空位上
            list[j] = list[i];
        }
        // 此时i位于数组中央, 放基准数
        list[i] = pivot;
        quickSort(list, low, i - 1);
        quickSort(list, i + 1, high);
    }
    return;
}

 int main() {
    vector<int> in;
    in.push_back(3);
    in.push_back(7);
    in.push_back(4);
    in.push_back(1);
    in.push_back(4);
    in.push_back(8);
    in.push_back(9);
    in.push_back(0);
    quickSort(in, 0, in.size()-1);
    for(int i = 0; i < in.size(); i++) {
        cout << in[i] << endl;
    }
    return 0;
 }