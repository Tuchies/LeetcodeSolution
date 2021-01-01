package top.pusenyang.leetcode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 */
public class L002 {

    class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {this.val = val;}
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode arr2ListNode(String[] arr) {
        // the node before headNode
        ListNode dummy = new ListNode(-1);
        ListNode preNode = dummy;
        for (String s : arr) {
            preNode.next = new ListNode(Integer.parseInt(s));
            preNode = preNode.next;
        }
        return dummy.next;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode n1 = l1;
        ListNode n2 = l2;
        ListNode pre = dummy;
        int carry = 0;
        while (n1 != null ||
                n2 != null) {
            int x = (n1 == null) ? 0 : n1.val;
            int y = (n2 == null) ? 0 : n2.val;
            int currentDigit = x + y + carry;
            carry = currentDigit / 10;
            // init current node
            pre.next = new ListNode(currentDigit % 10);
            // move pointer
            pre = pre.next;
            if (n1 != null) n1 = n1.next;
            if (n2 != null) n2 = n2.next;
        }
        // resolve the last carry
        if (carry > 0) pre.next = new ListNode(carry);
        return dummy.next;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp1 = br.readLine().split(" ");
        String[] tmp2 = br.readLine().split(" ");

        L002 l = new L002();
        ListNode head1 = l.arr2ListNode(tmp1);
        ListNode head2 = l.arr2ListNode(tmp2);
        System.out.print(l.addTwoNumbers(head1, head2).val);
    }
}
