#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n);
        vector<int> suffix(n);
        int pre=1,suf=1;
        for (int i = 0; i < n; i++) {
           prefix[i]=pre;
           pre*=nums[i];
        }
        for(int i=n-1;i>=0;i--) {
            suffix[i]=suf;
            suf*=nums[i];
        }
        for(int i=0;i<n;i++)    {
            ans[i]=suffix[i]*prefix[i];
        }
        return ans;
    }
};
