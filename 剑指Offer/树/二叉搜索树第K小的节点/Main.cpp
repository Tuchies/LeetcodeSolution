/**
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
 */

/**
 * 思路:
 *  根据二叉搜索树的左小右大特性, 它的中序遍历序列会是一个从小到大的数组, 进而可以求得第K小的节点
 * 
 * 对于本地来说, 没必要求得完整的中序遍历序列, 先遍历左子树, 直到最左的叶子节点, 此时在栈中的节点, 从栈顶到底 从小到大
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {}
};

TreeNode* KthNode(TreeNode* pRoot, int k) {
    if(pRoot == NULL || k == 0)
        return NULL;
    // 非递归中序遍历
    stack<TreeNode*> stack;
    int count = 0;
    TreeNode* node = pRoot;
    do{
        // 将左子树入栈, 直到最左的叶子节点
        // 此时在栈中的节点, 从栈顶到底 从小到大
        if(node != NULL){
            stack.push(node);
            node = node->left;
        }
        // 到达最左的叶子节点之后, 找第k个节点, 即是所求
        else{
            node = stack.top();
            stack.pop();
            count ++;
            if(count == k)
                return node;
            node = node->right;
        }
    } while(node != NULL || !stack.empty());
    return NULL;
}

