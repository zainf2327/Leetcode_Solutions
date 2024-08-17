#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n);
         ans[0] = nums[0];
        for(int i=1;i<n;i++)  {
            ans[i] = nums[i]+ans[i-1];
        }
        return ans;
    }
};