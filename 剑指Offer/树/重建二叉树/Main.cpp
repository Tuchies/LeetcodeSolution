/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */

/**
 * 参考: https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6?f=discussion
 * 
 * 思路解析: 
 * 1. 前序遍历序列的第一个数字是根节点的值, 对应的在中序遍历序列的中间, 由此确定根节点, 以及左右子树节点的个数和值
 * 2. 对于根节点划分来的左右子树, 递归的创建它们的左右子树
 */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

TreeNode* helper(vector<int> pre,int startPre,int endPre,vector<int> vin,int startVin,int endVin);

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode* root = helper(pre,0,pre.size()-1,vin,0,vin.size()-1);
    return root;
}

TreeNode* helper(vector<int> pre,int startPre,int endPre,vector<int> vin,int startVin,int endVin) {
    // 边界判断
    if(startPre > endPre || startVin > endVin)
        return NULL;
    // 1.初始化根节点: 永远是前序遍历的首元素    
    TreeNode* root = new TreeNode(pre[startPre]);
    // 2.遍历中序遍历, 区分左右子树    
    for(int i = startVin; i <= endVin; i++)
        if(vin[i] == pre[startPre]) {
            // 2.1左子树递归创建
            // 关键在于左右子树的索引范围界定
            root->left = helper(pre,startPre+1,startPre+i-startVin,vin,startVin,i-1);
            // 2.2右子树递归创建
            root->right= helper(pre,i-startVin+startPre+1,endPre,vin,i+1,endVin);
            break;
        }
                
    return root;
}

int main() {
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    cout << reConstructBinaryTree(pre,vin)->val << endl;
    return 0;
}

