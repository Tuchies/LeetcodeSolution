package top.pusenyang.leetcode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class L004 {

    public double findMedian (int[] nums) {
        int len = nums.length;
        if ((len & 1) == 0) {
            return (nums[len / 2] + nums[len / 2 - 1]) / 2.0;
        }
        else {
            return nums[len / 2];
        }
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        // special case
        if (m == 0 && n == 0 ) return 0.0;
        if (m == 0) return findMedian(nums2);
        if (n == 0) return findMedian(nums1);

        int[] list = new int[m + n];
        // 双指针遍历合并两个数组
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            // 找出小的, 将他的指针后移
            if (nums1[i] <= nums2[j]) {
                list[k ++] = nums1[i];
                i ++;
            }
            else {
                list[k ++] = nums2[j];
                j ++;
            }
        }
        // 对于长数组, 把后续的元素放完
        if (i < m) {
            for (int x = i; x < m; x ++) {
                list[k ++] = nums1[x];
            }
        }
        if (j < n) {
            for (int y = j; y < n; y ++) {
                list[k ++] = nums2[y];
            }
        }
        // 计算中位数
       return findMedian(list);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int count1 = Integer.parseInt(tmp[0]);
        int count2 = Integer.parseInt(tmp[1]);
        int[] nums1 = new int[count1];
        int[] nums2 = new int[count2];
        String[] tmp1 = br.readLine().split(" ");
        String[] tmp2 = br.readLine().split(" ");
        for (int i = 0; i < count1; i++) {
            nums1[i] = Integer.parseInt(tmp1[i]);
        }
        for (int i = 0; i < count2; i++) {
            nums2[i] = Integer.parseInt(tmp2[i]);
        }

        L004 l = new L004();
        System.out.printf("%f", l.findMedianSortedArrays(nums1, nums2));
    }
}
