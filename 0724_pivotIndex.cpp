#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0, suffixSum = sum;

        for (int i = 0; i < nums.size(); i++) {
            suffixSum = suffixSum - nums[i];
            if (prefixSum == suffixSum) {
                return i;
            }
            prefixSum += nums[i];
        }
        return -1;
    }
};