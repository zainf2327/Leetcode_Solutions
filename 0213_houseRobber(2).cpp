#include <vector>
using namespace std;

class Solution {
private:
    int rob(vector<int>& nums,int l,int r) {
        int last2=0;
        int last1=0;
        for(int i=l;i<=r;i++)    {
            int curr=max(nums[i]+last2,last1);
            last2=last1;
            last1=curr;
        }
        return last1;
        
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        return max(rob(nums,0,n-2),rob(nums,1,n-1));
        
    }
};