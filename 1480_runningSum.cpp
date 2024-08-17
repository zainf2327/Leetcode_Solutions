#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n =nums.size();
        int runningSum=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            runningSum+=nums[i];
            ans[i]=runningSum;
        }
        return ans;
    }
};