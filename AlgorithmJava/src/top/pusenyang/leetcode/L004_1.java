package top.pusenyang.leetcode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class L004_1 {

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
