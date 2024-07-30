#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector< int>> res;
        int left,right;
        long long sum;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])  continue;
                    left =j+1;
                    right = n-1;
                    while(left<right)   {
                        if(left>j+1 && nums[left]==nums[left-1])    {
                            left++;
                            continue;
                        }
                        if(right < n-1 && nums[right]==nums[right+1])  {
                            right--;
                            continue;
                        }
                        sum= nums[i];
                        sum=sum+nums[j]+nums[left]+nums[right];
                        if(sum==target) { 
                            res.push_back({nums[i],nums[j],nums[left],nums[right]});
                            left++;
                            right--;
                        }   
                        else if(sum<target) {
                            left++;
                        }
                        else    {
                            right--;
                        }
                   }
                
                }
        }
        return res;
    }
       
};
