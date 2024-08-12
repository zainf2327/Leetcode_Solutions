#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] != 0) {
                swap(nums[l], nums[r]);
                ++l;
            }
        }
        // l( indexes:0 to (l-1) is size of modified array having no element as zero but relative order is same. All zeros are to right of l i.e, n-l  (indexes range:(l+1)to(n-1))
    }
};
