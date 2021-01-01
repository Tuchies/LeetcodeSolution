#include<iostream>
#include<vector>
using namespace std;
 
// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index) {
    // index的左子节点
    int left = 2*index + 1; 
    // index的右子节点
    int right = 2*index + 2;
 
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx]) 
        maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx]) 
        maxIdx = right;
 
    if(maxIdx != index) {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
// 堆排序
void heapSort(vector<int> &arr, int size) {
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=size/2 - 1; i >= 0; i--) {
        adjust(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--) {
        // 将当前最大的放置到数组末尾
        swap(arr[0], arr[i]);           
        // 将未完成排序的部分继续进行堆排序
        adjust(arr, i, 0);              
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
    heapSort(in, in.size());
    for(int i = 0; i < in.size(); i++) {
        cout << in[i] << endl;
    }
    return 0;
}