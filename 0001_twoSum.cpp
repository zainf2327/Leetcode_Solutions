#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
 vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> arrMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arrMap[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (arrMap.count(complement) && arrMap[complement] != i) {
                return {i, arrMap[complement]};
            }
        }

        return {}; //Return empty vector in case no pair of numbers are found that adds to target.
    }
};


