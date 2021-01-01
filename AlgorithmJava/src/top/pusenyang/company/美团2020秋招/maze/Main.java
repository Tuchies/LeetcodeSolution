package top.pusenyang.company.美团2020秋招.maze;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 小团在一次星际旅行中，耗尽了飞船的能量，迷失在了空间魔方中，空间魔方中有N*N*N个能量粒子。美团云AI迅速帮小团分析出了空间魔方的能量分布图。
 *
 * 已知小团的飞船被困在能量值最高的点，能量值最高点有且只有一个。飞船每到达一个能量粒子就会吸收对应粒子的能量，该粒子会坍缩成小黑洞，飞船不可到达。小团驾驶的飞船只能从高能粒子驶向低能粒子，且每次只能从6个方向中选择一个前进。（±x,±y,±z）。
 *
 * 请帮助帮小团吸收最高的能量值。
 *
 *
 * 输入描述:
 * N（0≤N≤8）
 *
 * N*N*N行空间能量数据，格式为：X Y Z P，XYZ表示点坐标，P表示空间能量分布（0≤P）
 *
 *
 * 输出描述:
 * 输出一个整数，表示可吸收到的最高的能量值
 *
 *
 * 输入例子1:
 * 2
 * 0 0 0 7
 * 0 0 1 2
 * 0 1 0 4
 * 0 1 1 3
 * 1 0 0 6
 * 1 0 1 1
 * 1 1 0 5
 * 1 1 1 0
 *
 * 输出例子1:
 * 28
 *
 * 输入例子2:
 * 3
 * 0 0 0 1
 * 0 0 1 2
 * 0 0 2 3
 * 0 1 0 4
 * 0 1 1 5
 * 0 1 2 6
 * 0 2 0 7
 * 0 2 1 8
 * 0 2 2 9
 * 1 0 0 10
 * 1 0 1 11
 * 1 0 2 12
 * 1 1 0 13
 * 1 1 1 14
 * 1 1 2 13
 * 1 2 0 12
 * 1 2 1 11
 * 1 2 2 10
 * 2 0 0 9
 * 2 0 1 8
 * 2 0 2 7
 * 2 1 0 6
 * 2 1 1 5
 * 2 1 2 4
 * 2 2 0 3
 * 2 2 1 2
 * 2 2 2 1
 *
 * 输出例子2:
 * 89
 */
public class Main {

    static class Point {
        int x;
        int y;
        int z;
        int p;

        public Point(int x, int y, int z, int p) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.p = p;
        }
    }

    public int getRes(Point[] list) {
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Point[] list = new Point[n * n * n];
        Main m = new Main();
        for (int i = 0; i < n * n * n; i ++ ) {
            String[] tmp = br.readLine().split(" ");
            list[i] = new Point(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), Integer.parseInt(tmp[2]), Integer.parseInt(tmp[3]));
        }
        System.out.print(m.getRes(list));
    }
}
