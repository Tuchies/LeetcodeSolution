// 前序遍历: 迭代解法, 借助栈, 目的是延迟访问

/**
 * 到一个节点A, 首先看到的是它的根root, 访问它, 在访问根节点之后, 遍历左子树之前, 将右子树压入栈
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> list;
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || s.size()){

        while (current) {
            // 1.访问根节点之后,左子树之前, 将右子树入栈
            list.push_back(current->val);
            s.push(current->right);

            // 2.遍历左子树
            current = current->left;
        }
        // 3.最后处理右子树
        current = s.top();
        s.pop();
    }
    return list;
}

 
