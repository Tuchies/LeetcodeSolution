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
    TreeNode* current = root;
    while(current || s.size()) {
        // 1.跟入栈, 并遍历左子树
        while (current) {
           // 看到根节点就入栈, 延迟访问
           s.push(current);
           // 先访问左子树
           current = current->left;
        }
        // 2.左子树完毕后访问栈中的根, 栈顶的是最近的根, 访问完之后弹出它
        current = s.top(); s.pop();
        list.push_back(current->val);
        // 3.处理右子树
        current = current->right;
    }
    return list;
}
