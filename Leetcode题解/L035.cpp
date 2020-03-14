#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() <= 0 || nums[0] >= target) return 0;
    if (nums[nums.size() - 1] < target) return nums.size();
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] < target && nums[i + 1] >= target) {
            return i + 1;
        }
    }
}

int main() {
    vector<int> nums;
    // test case
    int target1 = 0, target2 = 4, target3 = 8,target4 = 1;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    __mingw_printf("%d", search(nums, target4));

    return 0;
}