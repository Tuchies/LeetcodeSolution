package top.pusenyang.algorithm.sort;

/**
 * 选择排序
 */
public class SelectionSort {

    public void selectionSort(int[] list) {
        int n = list.length;
        if (n < 2) return;
        for (int i = 0; i < n; i++) {
            int minIndex = i;
            for (int j = i; j < n; j ++) {
                if (list[minIndex] > list[j]) minIndex = j;
            }
            int tmp = list[i];
            list[i] = list[minIndex];
            list[minIndex] = tmp;
        }
    }

    public static void main(String[] args) {
        int[] list = new int[]{1, 3, 4, 8, 5, 0};
        SelectionSort ss = new SelectionSort();
        ss.selectionSort(list);
        for (int i : list) {
            System.out.println(i);
        }
    }
}
