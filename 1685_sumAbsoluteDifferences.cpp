#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int suffixSum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            suffixSum -= nums[i];
            int leftCount = i;
            int rightCount = n - 1 - i;
            int leftTotal = (nums[i] * leftCount) - prefixSum;
            int rightTotal = suffixSum - (nums[i] * rightCount);
            res.push_back(leftTotal+rightTotal);
            prefixSum += nums[i];
        }
        return res;
    }
};