#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<pair<int,int>> num_indices; // Vector pair holding value of array as first value and index of value of array as second value in vector array.
         int size =nums.size();
         for(int i= 0;i<size;i++) {
            num_indices.push_back({nums[i],i});
         }

         sort(num_indices.begin(),num_indices.end()); 
          // sort the vector pairs based on first value keeping the second value intact to original number and if first values are same then sorts according to second value.
         int start=0, end = size-1,sum=0;
         while(start<end)   {
            sum=num_indices[start].first+num_indices[end].first;
            if(sum==target)
                return { num_indices[start].second , num_indices[end].second };
            else if(sum>target)
                end--;
            else
               start++;
         }

         // Returns empty vector in case of no pair of numbers are found that add to target.
         return {};
    }
};

