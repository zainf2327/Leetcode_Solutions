#include <vector>
using namespace std;
class Solution {
int maxMoney(int i,vector<int>& nums,vector<int>&dp) {
    if(i==0) return nums[0];
    if(dp[i]!=-1)return dp[i];
    int rob=0;
    if(i-2>=0) rob=nums[i]+maxMoney(i-2,nums,dp);
    int notRob=maxMoney(i-1,nums,dp);
    return dp[i]=max(rob,notRob);

}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        return maxMoney(nums.size()-1,nums,dp);
        
    }
};