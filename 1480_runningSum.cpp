#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};