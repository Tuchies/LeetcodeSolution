// 二叉树的前序遍历: 递归解法


#include<iostream>
#include<vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
vector<int> list;
vector<int> preorderTraversal(TreeNode *root) {
    if (root != NULL) {
        // 前序遍历: 先放根节点
        list.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return list;
}   

int main() {
    
}