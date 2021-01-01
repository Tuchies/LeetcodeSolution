package top.pusenyang.algorithm.sort;

import java.util.Arrays;

/**
 * 归并排序
 */
public class MergeSort {

    public int[] mergeSort(int[] list) {
        int n = list.length;
        if (n < 2) return list;
        int mid = n / 2;
        int[] left = Arrays.copyOfRange(list, 0, mid);
        int[] right = Arrays.copyOfRange(list, mid, n);
        return merge(mergeSort(left), mergeSort(right));
    }

    public int[] merge(int[] left, int[] right) {
        int ln = left.length, rn = right.length;
        int[] result = new int[ln + rn];
        for (int index = 0, i = 0, j = 0; index < result.length; index ++) {
            if (i >= ln) {
                result[index] = right[j++];
            }
            else if (j >= rn) {
                result[index] = left[i++];
            }
            else if (left[i] > right[j]) {
                result[index] = right[j++];
            }
            else {
                result[index] = left[i++];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] list = new int[]{1, 3, 4, 8, 5, 0};
        MergeSort ms = new MergeSort();
        int[] res = ms.mergeSort(list);
        for (int i : res) {
            System.out.println(i);
        }
    }
}
