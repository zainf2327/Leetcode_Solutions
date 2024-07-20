#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)    {          
        int n = nums.size();
        if (n < 3) return {};               //Base case 1

        sort(nums.begin(), nums.end());     // Sorted Array
        if (nums[0] > 0)  return {};        //Base case 2
        vector<vector<int>> triples;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;      // As target is 0,so positive numbers can't become zero by adding more positive numbers.
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // If 1st fixed number is equal to previous one,then continue to avoid duplicates.
            int start = i+1,end = n-1;
            while(start<end)    {      // Two pointers Approach
                int sum = nums[i]+nums[start]+nums[end];
                if(sum==0)  {                           // target is 0 in this case.
                    triples.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while( start<end && nums[start]==nums[start-1]) start++;  //Updating start until last occurence of nums[start] to avoid duplicates.
                    while( start<end && nums[end]==nums[end+1]) end--;        //Updating end until last occurence of nums[end] to avoid duplicates.

                }
                else if(sum>0)
                    end--;
                else
                    start++;
            }
                    
        }
        
        return triples;
    }       
    
};