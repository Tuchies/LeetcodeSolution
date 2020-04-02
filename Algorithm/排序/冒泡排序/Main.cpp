// 冒泡排序：一种简单的比较排序算法
// 思路：比较相邻两个元素，小的在前，大的在后。一趟遍历后，最大元素会被置换到最后....多次重复该过程，直到 j=0

#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> in){
    if(in.size() < 2) return in;
    for(int i = 0; i < in.size()-1; i++) {
        for (int j = 0; j < in.size()-1-i; j++){
            if(in[j] > in[j+1]) { //换位
                int temp = in[j+1];
                in[j+1] = in[j];
                in[j] = temp;
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
    vector<int> r = bubbleSort(in);
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }
    return 0;
}