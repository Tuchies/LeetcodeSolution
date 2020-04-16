// 后序遍历: 栈+标记

/**
 * 来源: 作者：jason-2
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/
 * 
 每到一个节点 A，因为根要最后访问，将其入栈。然后遍历左子树，遍历右子树，最后返回到 A。

但是出现一个问题，无法区分是从左子树返回，还是从右子树返回。

因此，给 A 节点附加一个标记T。在访问其右子树前，T 置为 True。之后子树返回时，当 T 为 True表示从右子树返回，否则从左子树返回。

当 T 为 false 时，表示 A 的左子树遍历完，还要访问右子树。

同时，当 T 为 True 时，表示 A 的两棵子树都遍历过了，要访问 A 了。并且在 A 访问完后，A 这棵子树都访问完成了。
*/

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
    stack<TreeNode*> s;
    map<TreeNode*, int> flag;
    vector<int> list;
    TreeNode* current = root;

    while(current || s.size()){
        while(current){
            // 1. 遇到根节点就入栈, 延迟访问
            s.push(current);
            // 2. 遍历左子树
            current = current->left;
        }
        // 3.栈不为空, 且栈顶元素标记为 true, 即左右子树都遍历完了, 访问根节点; 如果左子树遍历完了, 右子树还没有, 就跳过这
        while(s.size() && flag[s.top()]){
            list.push_back(s.top()->val);
            s.pop();
        }
        if(s.size()){
            // 左子树遍历完了, 处理右子树, 并修改标记
            current = s.top()->right;
            flag[s.top()]=1;    
        }
    }
    return list;
}