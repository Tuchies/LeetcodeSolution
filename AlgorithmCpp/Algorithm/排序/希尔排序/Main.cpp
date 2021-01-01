// 希尔排序：简单插入排序的改进版
// 思路：取小于size的整数d1做为第一个增量，对所有元素分组，每个组内进行插入排序；再取d2<d1...重复该过程，直至所有元素到同一组中

// 提炼：其实就是在各分组中，再执行一次插入排序

#include<iostream>
#include<vector>

using namespace std;

vector<int> shellSort(vector<int> in) {
    if(in.size() < 2) return in;
    for(int gap = in.size()/2; gap > 0; gap /= 2) {
        for(int t = 0; t < gap; t ++) {
            // 开始简单插入排序
             int current, preIndex;
            for(int i = t+gap; i < in.size(); i += gap) {
                current = in[i];
                preIndex = i-1;
                for(; preIndex >= 0 && current < in[preIndex]; preIndex --) {
                    in[preIndex+1] = in[preIndex]; 
                }
                in[preIndex+1] = current;
            }
        }
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
    vector<int> r = shellSort(in);
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }
    return 0;
}