#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int j = 0; j < n; j++) {
            ans[j] = ans[j + n] = nums[j];
        }

        return ans;
    }
};
