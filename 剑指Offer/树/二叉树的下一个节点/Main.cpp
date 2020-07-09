/**
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */

/**
 * 参考: "剑指offer" 书中的官方解法
 * 思路: 关键在于找到中序遍历和树本身的联系规律 (可举例写出中序遍历反复揣摩)
 *  1. 如果一个节点有右子树, 则所求的下一个节点就是右子树中的最左节点
 *  2. 如果节点没有右子树, 且是父节点的左子节点, 则所求的下一个节点就是父节点
 *  3. 如果节点没有右子树, 且是父节点的右子节点, 则要向上遍历, 直到找到一个是其父节点的左子节点的节点, 并入情况2
 * 
 * 由于3最终还是要并入2, 故以上可以分为两种情况讨论
 */

#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :
        val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (pNode == nullptr) 
        return nullptr;

    TreeLinkNode* temp = nullptr;
    // 右孩子不为空
    if (pNode->right != nullptr) {
        TreeLinkNode* rNode = pNode->right;
        while(rNode->left != nullptr)
            rNode = rNode->left;
        temp = rNode;
    }
    // 右孩子为空, 但其父节点不为空
    else if (pNode->next != nullptr) {
        TreeLinkNode* cur = pNode;
        TreeLinkNode* par = pNode->next;
        while(par != nullptr && cur == par->right) {
            cur = par;
            par = par->next;
        }
        temp = par;
    }
    return temp;
}