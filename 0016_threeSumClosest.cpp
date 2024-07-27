#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)  {
        int n = nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int sum=0,closestSum= nums[0]+nums[1]+nums[2];   // can also be INT_MAX/10 .
        int start,end;

        for(int i =0;i<n-2;i++) {
            start=i+1,end=n-1;
            while(start<end)   {
                sum=nums[i]+nums[start]+nums[end];
                if(sum==target) return target;
                if(abs(target-sum)<abs(target-closestSum))  {
                    closestSum=sum;
                }
                if (sum > target)  {
                    end--;
                    while (start < end && nums[end] == nums[end + 1])  // Next triplet would be same, so don't need to check them.
                        end--;
                }

                else   {
                    start++;
                    while (start < end && nums[start] == nums[start - 1])   // Next triplet would be same, so don't need to check them.
                    start++;
                }             
            }        
            
        }
        return closestSum;     
    }
};
