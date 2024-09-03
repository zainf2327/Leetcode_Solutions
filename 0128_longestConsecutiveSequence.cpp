#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (seen.count(nums[i] - 1))
                continue;
            int current = 1;
            int x = nums[i] + 1;
            while (seen.count(x)) {
                x++;
                current++;
            }
            longest = max(longest, current);
        }
        return longest;
    }
};