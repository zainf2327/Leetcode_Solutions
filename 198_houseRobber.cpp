#include <vector>
using namespace std;

class Solution {
int maxMoney(int i,vector<int>& nums,vector<int>&dp) {
    if(i==0) return nums[0];
    if(dp[i]!=-1)return dp[i];
    int rob=nums[i];
    if(i-2>=0) rob+=maxMoney(i-2,nums,dp);
    int notRob=maxMoney(i-1,nums,dp);
    return dp[i]=max(rob,notRob);

}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int last2=0;
        int last1=0;
        for(int i=0;i<n;i++)    {
            int curr=max(nums[i]+last2,last1);
            last2=last1;
            last1=curr;
        }
        return last1;
        
    }
};