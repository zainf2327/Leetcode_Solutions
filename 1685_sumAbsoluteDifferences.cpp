#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += abs(nums[i] - nums[j]);
            }
            res.push_back(sum);
        }
        return res;
    }
};