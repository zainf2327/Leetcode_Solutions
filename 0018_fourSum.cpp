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
        unordered_map<long long int, int> arrMap;
        for (int i = 0; i < n; i++) {
            arrMap[nums[i]] = i;
        }
        vector<vector< int>> res;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1; k < n - 1; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    long long int complement = (long long)target -1*( (long long)nums[i] +nums[j] + nums[k]);
                    if (arrMap.count(complement) && arrMap[complement] > k) {
                        res.push_back({nums[i], nums[j], nums[k], (int)complement});
                    }
                }
            }
        }
        return res;
    }
       
};
