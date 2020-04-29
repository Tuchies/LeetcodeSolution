// 中序遍历的迭代解法: 借助栈实现

/* 思路:

每到一个节点 A，因为根的访问在中间，将 A 入栈。然后遍历左子树，接着访问 A，最后遍历右子树。

在访问完 A 后，A 就可以出栈了。因为 A 和其左子树都已经访问完成。
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> list;
    stack<TreeNode*> s;
    if (root != NULL) {
        TreeNode* cur = root;
        while(cur != NULL || !s.empty()) {
            if (cur != NULL) {
                // 入栈
                s.push(cur);
                cur = cur->left;
            } else {
                // 出栈访问, 并观察有无右子树
                cur = s.top();
                s.pop();
                list.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return list;
}
