#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    bool search(vector<int>& nums, int x) {
        for (int a : nums) {
            if (a == x)
                return true;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (search(nums, nums[i] - 1))
                continue;
            int x = nums[i] + 1;
            int length = 1;
            while (search(nums, x)) {
                x++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};