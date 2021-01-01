package top.pusenyang.algorithm.sort;

public class BubbleSort {

    public void bubbleSort(int[] list) {
        int n = list.length;
        if (n < 2) return ;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j ++) {
                // change
                if (list[j] > list[j + 1]) {
                    int tmp = list[j + 1];
                    list[j + 1] = list[j];
                    list[j] = tmp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] list = new int[]{1, 3, 4, 8, 5, 0};
        BubbleSort bs = new BubbleSort();
        bs.bubbleSort(list);
        for(int i : list) {
            System.out.println(i);
        }
    }
}
