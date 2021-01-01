package top.pusenyang.algorithm.sort;

/**
 * 快速排序
 */
public class QuickSort {

    public void quickSort(int[] list, int low, int high) {
        int i = low, j = high;
        if (i >= j) return; // 递归出口
        int pivot = list[i];
        while (i != j) {
            while (j > i && list[j] >= pivot) j --;
            list[i] = list[j];
            while (j > i && list[i] <= pivot) i ++;
            list[j] = list[i];
        }
        list[i] = pivot;
        quickSort(list, low, i - 1);
        quickSort(list, i + 1, high);
    }

    public static void main(String[] args) {
        int[] list = new int[]{1, 3, 4, 8, 5, 0};
        QuickSort qs = new QuickSort();
        qs.quickSort(list, 0, list.length - 1);
        for (int i : list) {
            System.out.println(i);
        }
    }
}
