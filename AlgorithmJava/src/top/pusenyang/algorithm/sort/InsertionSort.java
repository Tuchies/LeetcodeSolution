package top.pusenyang.algorithm.sort;

public class InsertionSort {

    public void insertionSort(int[] list) {
        int n = list.length;
        if (n < 2) return;
        int current, preIndex;
        for (int i = 1; i < n; i ++) {
            preIndex = i - 1;
            current = list[i];
            for (; preIndex >= 0 && current < list[preIndex]; preIndex --) {
                list[preIndex + 1] = list[preIndex];
            }
            list[preIndex + 1] = current;
        }
    }

    public static void main(String[] args) {
        int[] list = new int[]{1, 3, 4, 8, 5, 0};
        InsertionSort is = new InsertionSort();
        is.insertionSort(list);
        for (int i : list) {
            System.out.println(i);
        }
    }
}
