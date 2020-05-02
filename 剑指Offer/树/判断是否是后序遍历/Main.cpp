/*
输入一个非空整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

/*
对于后续遍历, 最后一个元素一定是根节点; 去掉该节点之后, 数组可以分为两半, 一半是左子树, 一半是右子树, 递归判断这两半
*/

#include<iostream>
#include<vector>

using namespace std;

// 判断函数
bool judge(vector<int>& list, int leftIndex, int rightIndex){
    // 边界检查
    if(leftIndex >= rightIndex) 
        return true;
    int i = rightIndex;
    while(i > leftIndex && list[i - 1] > list[rightIndex]) 
        --i;
    for(int j = i - 1; j >= leftIndex; --j) {
        if(list[j] > list[rightIndex]) 
            return false;
    }
    return judge(list, leftIndex, i - 1) && (judge(list, i, rightIndex - 1));
}

bool VerifySquenceOfBST(vector<int> list) {
    if(list.size() < 1) return false;
    return judge(list, 0, list.size() - 1);
}

int main() {
    int n;
    vector<int> list;
    while(cin >> n) {
        list.push_back(n);
    }
    cout << VerifySquenceOfBST(list);
    return 0;
}