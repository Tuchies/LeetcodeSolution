/**
 * 请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树
*/

/**
 * 参考: "剑指offer"书中的解法
 * 思路: 
 *  1. 序列化: 从前序遍历序列化二叉树, 空字符用#替代, 数值之间用,隔开
 *  2. 反序列化: 递归得反序列化根节点, 左子树和右子树
 */

#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {}
};

char* Serialize(TreeNode *root) {
    if(root == NULL)
        return NULL;
    string str;
    Serialize(root, str);
    char *ret = new char[str.length() + 1];
    int i;
    for(i = 0; i < str.length(); i++){
        ret[i] = str[i];
    }
    ret[i] = '\0';
    return ret;
}
void Serialize(TreeNode *root, string& str){
    if(root == NULL){
        str += '#';
        return ;
    }
    string r = to_string(root->val);
    str += r;
    str += ',';
    Serialize(root->left, str);
    Serialize(root->right, str);
}
    
TreeNode* Deserialize(char *str) {
    if(str == NULL)
        return NULL;
    TreeNode *ret = Deserialize(&str);

    return ret;
}
TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
    if(**str == '#'){  //所以一定要用**str,
        ++(*str);         //以保证得到递归后指针str指向未被读取的字符
        return NULL;
    }
    int num = 0;
    while(**str != '\0' && **str != ','){
        num = num*10 + ((**str) - '0');
        ++(*str);
    }
    TreeNode *root = new TreeNode(num);
    if(**str == '\0')
        return root;
    else
        (*str)++;
    root->left = Deserialize(str);
    root->right = Deserialize(str);
    return root;
}