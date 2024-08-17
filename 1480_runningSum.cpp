#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prefixSum + nums[i];
            prefixSum += nums[i];
        }
        return ans;
    }
};