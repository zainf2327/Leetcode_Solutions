# include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (nums[0] != nums[1])
            return nums[0];
        else if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int l = 1, r = n - 2;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])
                return nums[m];
            if (m % 2 == 0 && nums[m] == nums[m + 1] ||      // left half of single element of we have (even,odd) of duplicate elements while on right half of single element of we have (odd,even) of duplicate elements
                m % 2 == 1 && nums[m] == nums[m - 1]) {
                l = m + 1;
            } else {                      // if we are in right half
                r = m - 1;
            }
        }
        return -1;
    }
};