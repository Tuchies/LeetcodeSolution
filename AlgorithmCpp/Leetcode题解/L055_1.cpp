// 贪心算法思路：基于之前动态规划的从后往前思路，我们可以直接从数组末位开始遍历数组；定义标志位flag为当前节点，初始化为flag = vector.size()-1；向前遍历，如果前面节点可以到达标志位，就移动标志位；最后判断标志位是否能到达0即可

// 一个疑问点：从后往前遍历，得到的可到达节点s一定是离标志位最近的那个，如果前边有节点可以到达标志位，则一定可以到达s节点

// 这也是本问题中“贪心”思路的体现，即不从整体考虑问题，只找到那个最近的可到达点；前提是根据该贪心性质可以得到目标问题的正确解

#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() < 1) return false;
    int flag = nums.size() - 1;

    // 从后往前遍历数组
    for(int i = nums.size() - 1; i >= 0; i --) {
        // 判断前面节点能否到达标志位
        if(nums[i] + i >= flag) {
            // 如果可以，就移动标志位
            flag = i;
        }
    }
    return flag == 0;
}

int main() {
    vector<int> in;
    in.push_back(3);
    in.push_back(2);
    in.push_back(1);
    in.push_back(0);
    in.push_back(4);

    cout << canJump(in) << endl;
    return 0;
}
