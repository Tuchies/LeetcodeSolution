// 递归解法：需要经每次访问的节点都放置在数组中，因此需要构建辅助函数

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

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> list;
    helper(root, list);
    return list;
}   

void helper(TreeNode *root, vector<int> list) {
    if (root != NULL) {
        helper(root->left, list);
        list.push_back(root->val);
        helper(root->right,list);
    }
}

int main() {
    
}

