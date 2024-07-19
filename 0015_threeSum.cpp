#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)    {          
        int n = nums.size();        // size of array
        
        if (n < 3)  return {};    // Base Case 1

        sort(nums.begin(), nums.end());  // Sorting of array

        if (nums[0] > 0)    return {};   // Base Case 2
        
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++)    {
            hashMap[nums[i]] = i;        // Hashing of indices
        }

        vector<vector<int>> triples;
        
        for (int i = 0; i < n - 2; i++)    {   //Fixing 1st number to tranverse the array

            if (nums[i] > 0)    break;      // if fixed number is +ve, stop it since leading elements would ony increase the sum and we cannot acheive 0(target).(only if target==0)
            
            for (int j = i + 1; j < n - 1; j++)    {   //Fixing 2nd number

                
                int complement = -1 * (nums[i] + nums[j]);     //complement = target - nums[i]-nums[j]

                if (hashMap.count(complement) && hashMap[complement] > j)
                        triples.push_back({nums[i], nums[j], complement});      //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.

                j=hashMap[nums[j]];                     //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }

            i=hashMap[nums[i]];                       //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return triples;
    }       
    
};