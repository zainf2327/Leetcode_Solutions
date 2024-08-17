#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (r == 0 || r == 1 || nums[r] != nums[l - 2]) {
                nums[l] = nums[r];  // swap(nums[l],nums[r]);
                l++;
            }
        }
        return l;
    }
};