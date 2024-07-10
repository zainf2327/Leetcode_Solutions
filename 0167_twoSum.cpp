#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target)   {
        for(int i=0;i<nums.size()-1;i++)    {
             for(int j=i+1;j<nums.size();j++)   {
                if(nums[j] == target - nums[i])
                    return {i+1,j+1}; // 1-based index array

             }
        }
        // Return empty vector in case of no pair of numbers found that add to target.
        return {};
    }
};
    