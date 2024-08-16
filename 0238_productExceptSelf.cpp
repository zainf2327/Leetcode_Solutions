#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Prefix Product -- Suffix product in ans vector
       int n = nums.size();
        vector<int> ans(n);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int j = n - 1; j >= 0; j--) {
            ans[j] *= suffix;
            suffix *= nums[j];
        }

        return ans;
    }
};
