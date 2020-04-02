// 选择排序：
// 思路：不断从无序区寻找最小元素放置在有序区的末尾，直到无序区缩小至无

#include<iostream>
#include<vector>

using namespace std;

vector<int> selectionSort(vector<int> in) {
    if(in.size() < 2) return in;
    for(int i = 0; i < in.size(); i ++) {
        int minIndex = i;
        for(int j = i; j < in.size(); j++) {
            if(in[minIndex] > in[j]) 
                minIndex = j;
        }
        int temp = in[i];
        in[i] = in[minIndex];
        in[minIndex] = temp;
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
    vector<int> r = selectionSort(in);
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }
    return 0;
}