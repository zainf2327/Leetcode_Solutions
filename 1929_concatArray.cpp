#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
          // General Approach if you have to concatenate k times in ans array
        vector<int> ans(2 * n);
        for (int i = 0; i < 2; i++) {   // Number of concatenations in resultant array
            for (int j = 0; j < n; j++) {
                ans[j + n * i] = nums[j];
            }
        }
        return ans;
    }
};
