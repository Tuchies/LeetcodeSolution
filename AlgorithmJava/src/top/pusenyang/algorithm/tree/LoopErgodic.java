package top.pusenyang.algorithm.tree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class LoopErgodic {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    // 前序遍历
    List<Integer> preOrderList = new ArrayList<>();
    public List<Integer> preorder(TreeNode node) {
        if (node == null) return preOrderList;
        Stack<TreeNode> st = new Stack<>();
        TreeNode cur = node;
        while (! st.empty() || cur != null) {
            while(cur != null){
                // 把右子树入栈
                st.push(cur.right);
                // 记录
                preOrderList.add(cur.val);
                // 找左子树
                cur = cur.left;
            }
            // 弹出
            cur = st.pop();
        }
        return preOrderList;
    }

    // 中序遍历
    List<Integer> inOrderList = new ArrayList<>();
    public List<Integer> inorder(TreeNode node) {
        if (node != null) {
            inorder(node.left);
            inOrderList.add(node.val);
            inorder(node.right);
        }
        return inOrderList;
    }

    // 后序遍历
    List<Integer> postOrderList = new ArrayList<>();
    public List<Integer> postorder(TreeNode node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);
            postOrderList.add(node.val);
        }
        return postOrderList;
    }

    public static void main(String[] args) {
        // 示例二叉树
        TreeNode root = new TreeNode(1);
        TreeNode secondNode1 = new TreeNode(2);
        TreeNode secondNode2 = new TreeNode(3);
        TreeNode thirdNode1 = new TreeNode(4);
        TreeNode thirdNode2 = new TreeNode(5);

        root.left = secondNode1;
        root.right = secondNode2;
        secondNode1.left = thirdNode1;
        secondNode1.right = thirdNode2;

        LoopErgodic le = new LoopErgodic();
        System.out.print("前序遍历的结果是: \n");
        le.preorder(root).forEach(System.out::println);
        System.out.print("中序遍历的结果是: \n");
        le.inorder(root).forEach(System.out::println);
        System.out.print("后序遍历的结果是: \n");
        le.postorder(root).forEach(System.out::println);
    }
}
