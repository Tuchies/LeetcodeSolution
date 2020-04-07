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

// 辅助寻找基准数
int paritition(vector<int> &in, int low, int high) {    
    int pivot = in[low];
    while (low < high) {
        // 从后往前找小于基准数的
        while (low < high && in[high] >= pivot) {
            --high;
        }
        // 填坑
        in[low] = in[high];
        // 从前往后找大于基准数的
        while (low < high && in[low] <= pivot) {
            ++low;
        }
        // 填坑
        in[high] = in[low];
   }
   in[low] = pivot;
   return low;
 }

 void quickSort(vector<int>& in, int low, int high) 
 {
    if (low < high) {
        int pivot = paritition(in, low, high);
        quickSort(in, low, pivot - 1);
        quickSort(in, pivot + 1, high);
    }
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