#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        while (r < n) {
            if (!(nums[r] & 1)) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
        return nums;
    }
};