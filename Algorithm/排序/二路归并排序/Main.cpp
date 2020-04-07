// 二路归并排序：分治法的典型应用
// 思路：分为两个步骤
//      1.分: 将原有数组分为几段有序的子数组(这往往是单个元素)
//      2.治: 类似于合并两个链表,使用双指针, 比较指向的元素的大小,将小的放在新开辟的空间前部,指针后移

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &in, int le, int m, int r){
    // 左边数组大小
    vector<int> leftArray(m-le);
    // 右边数组大小
    vector<int> rightArray(r-m+1);

    // 给两个数组填充数据
    for (int i = le; i < m; i++) {
            leftArray[i - le] = in[i];
        }
    for (int i = m; i <= r; i++) {
        rightArray[i - m] = in[i];
    }

    int i = 0, j = 0;
    // arrays数组的第一个元素
    int  k = le;


    //比较这两个数组的值，哪个小，就往数组上放
    while (i < leftArray.size() && j < rightArray.size()) {
        //谁比较小，谁将元素放入大数组中,移动指针，继续比较下一个
        if (leftArray[i] < rightArray[j]) {
            in[k] = leftArray[i];

            i++;
            k++;
        } else {
            in[k] = rightArray[j];
            j++;
            k++;
        }
    }

    //如果左边的数组还没比较完，右边的数都已经完了，那么将左边的数抄到大数组中(剩下的都是大数字)
    while (i < leftArray.size()) {
        in[k] = leftArray[i];

        i++;
        k++;
    }

    //如果右边的数组还没比较完，左边的数都已经完了，那么将右边的数抄到大数组中(剩下的都是大数字)
    while (j < rightArray.size()) {
        in[k] = rightArray[j];

        k++;
        j++;
    }
}

void mergeSort(vector<int> &in, int left, int right) {
    if(left == right) return;

    //取中间的数进行拆分
    int middle = (left + right) / 2;
    //递归拆分左半边元素
    mergeSort(in, left, middle);
    //递归拆分右半边元素
    mergeSort(in, middle+1, right);

    //合并
    merge(in, left, middle+1, right);
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
    mergeSort(in, 0, in.size()-1);
    for(int i = 0; i < in.size(); i++) {
        cout << in[i] << endl;
    }
    return 0;
}