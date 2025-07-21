#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(const vector<int> &nums, int target)
    {
        unordered_map<int, int> arrMap;
        int size = nums.size(), complement;
        for (int i = 0; i < size; ++i)
        {
            complement = target - nums[i];
            if (arrMap.count(complement))
            {
                return {arrMap[complement], i};
            }
            arrMap[nums[i]] = i;
        }

        return {}; // returns an empty array if no pair of numbers are found
                   // that add to target.
    }
};
