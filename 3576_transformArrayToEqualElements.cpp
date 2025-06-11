# include <vector>
using namespace std;

class Solution {
private:
        bool makeAllX(vector<int> nums,int x,int k){
            int ope=0;
            int n=nums.size();
            for(int i=0;i<n-1;i++){
                if(nums[i]==x) continue;
                nums[i] *= -1;
                nums[i+1] *= -1;
                ope++;
            }
        return ope<=k && nums[n-1]==x;
        }
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        
       return makeAllX(nums,1,k) || makeAllX(nums,-1,k);
       
    }
};