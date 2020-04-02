// 插入排序：
// 思路：构建有序区，遍历无序区的元素; 在有序区从后往前扫描，找到位置插入，其余元素后移  
// 和选择排序比较：选择排序是不断在无序区找最小元素来构建有序区；插入是默认首元素为有序区，遍历无序区，再插入到有序区

/*实现：
    1.默认首元素为有序区，遍历后续元素；
    2.设current为当前正遍历的元素，preIndex为该元素前一个元素的下标；preIndex初始化为i-1；
    3.只要满足 前边还有元素且当前元素比前一个小(preIndex >= 0 && arr[preIndex] > current)，就把前一个元素后移，把preIndex下标前移
    4.最终current的位置为 preIndex+1
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> insertionSort(vector<int> in) {
    if(in.size() < 2) return in;
    int current, preIndex;
    for(int i = 1; i < in.size(); i ++) {
        preIndex = i-1;
        current = in[i];
        for( ;preIndex >= 0 && current < in[preIndex]; preIndex --) {
            in[preIndex+1] = in[preIndex];
        }
        in[preIndex+1] = current;
    }
    return in;
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
    vector<int> r = insertionSort(in);
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }
    return 0;
}