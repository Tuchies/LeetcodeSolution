/**
 * 爬楼梯问题的变式: 
 * 每次只能上一个或者两个台阶, 给定n, 输出一个二维数组, 表示所有可能的爬楼路径; 请按照字典顺序输出
 * 
 * 如: n=3, 输出: [[1,1,1],[1,2],[2,1]]
 */

public class Stairs {

	// 统计个数
	private int currentCount = 1;

	/**
	 * @param remainingSteps
	 *            ： 剩余的台阶数,开始调用的值是总的台阶数
	 * @param currentSteps
	 *            ： 递归过程中某种情况下，已经走的步骤，如 1 2 走了三步的情况
	 */
	public void walkStairs(int remainingSteps, String currentSteps) {
		/*
		 * 当剩下小于等于三级台阶时，输出楼梯的走法
		 */
		if (remainingSteps <= 3) {
			printWalkWays(remainingSteps, currentSteps);
		} else {
			for (int step = 1; step <= 3; step++) {
				walkStairs(remainingSteps - step, currentSteps + " " + step);
			}
		}
	}

	private StringBuilder getCurrentCountStepInformation(String currentSteps) {
		return new StringBuilder().append("第").append(currentCount++).append(
				"种走法").append(currentSteps);
	}

	/**
	 * 输出满足条件的台阶走法
	 * 
	 * @param remainingSteps
	 * @param currentSteps
	 */
	private void printWalkWays(int remainingSteps, String currentSteps) {
		if (1 == remainingSteps) {
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 1").toString());
		} else if (2 == remainingSteps) {
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 1 1").toString());
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 2").toString());
		} else if (3 == remainingSteps) {
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 1 1 1").toString());
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 1 2").toString());
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 2 1").toString());
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.append(" 3").toString());
		} else {
			/**
			 * 0 ==remainingSteps, 表明已经走完台阶了,直接输出就可以了
			 */
			System.out.println(getCurrentCountStepInformation(currentSteps)
					.toString());
		}
	}

}

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > getPath(int n) {

}

int main() {
    int n;
    scanf("%d",&n);
    vector<vector<int> > ans = getPath(n);
    return 0;
}