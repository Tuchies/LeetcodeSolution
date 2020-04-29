// 后序遍历: 双栈结构实现


#include<iostream>
#include<vector>
#include<stack>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
   vector<int> list;
   stack<TreeNode*> s1;
   stack<TreeNode*> s2;
   if (root != NULL) {
       TreeNode* cur = root;
       s1.push(cur);
       while(!s1.empty()) {
           cur = s1.top();
           s1.pop();
           s2.push(cur);
           // 栈1中先压入左子树
           if(cur->left != NULL) {
               s1.push(cur->left);
           }
            if (cur->right != NULL) {
                s1.push(cur->right);
            }
       }
       // 栈2出栈顺序, 左右跟
       while(!s2.empty()) {
           cur = s2.top();
           s2.pop();
           list.push_back(cur->val);
       }
   }
   return list;
}