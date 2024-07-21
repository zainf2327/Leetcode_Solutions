#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)  return {};          // Base case 1
        sort(nums.begin(), nums.end());
        if(nums [0]> 0 ) return {};     // Base case 2
        unordered_set<int> s;           // HashSet for storing the elements of array.
        vector<vector<int>> triples;

        for (int i = 0; i < n - 1; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1])    continue;   //avoid duplicates

            for (int j = i + 1; j < n; j++) { 

                int complement = -1*(nums[i] + nums[j]);
                if (triples.empty() || nums[j] != triples.back()[2] || nums[i] != triples.back()[0]) {   // Avoid Duplicates condition
                    if (s.count(complement))
                        triples.push_back({nums[i], complement, nums[j]});
                }
                s.insert(nums[j]);     
            }
            s.clear();   //Emptied HashSet
        }
        return triples;
    }
};
