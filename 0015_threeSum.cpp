#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {          
        set<vector<int>> temp;
        sort(nums.begin(),nums.end());                      // sort the array so when we get desired triplets, they are in sorted order,so as they would be added into set,they would be removed.
        int n =  nums.size();
        for(int i=0;i<n-2;i++)    {
            if(nums[i]>0) break;
            for(int j=i+1;j<n-1;j++)   {
                for(int k=j+1;k<n;k++)    {
                    if(nums[i]+nums[j]+nums[k]==0) {                // target in this case is 0. It can be any value
                         
                        temp.insert({nums[i],nums[j],nums[k]});            // insert the triple in map so that duplicates are removed
                    }
                }   
            }        
        }
        vector<vector<int>> ans (temp.begin(),temp.end()); // copy the elements of map(triples) into vector 
        return ans; // return the vector containing unique triples that add to zero.
    }       
    
};