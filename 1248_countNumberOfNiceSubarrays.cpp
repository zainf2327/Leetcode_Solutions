# include <vector>
using namespace std;

class Solution {
private:
    int numSubarraysWithOddAtmost(vector<int>& nums, int target) {
        if (target < 0)
            return 0;
        int count = 0;
        int l = 0;
        int odd = 0;
        for (int r = 0; r < nums.size(); r++) {
            odd = odd + (nums[r] % 2);
            while (odd > target) {
                odd = odd - (nums[l] % 2);
                l++;
            }

            count = count + (r - l + 1);
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarraysWithOddAtmost(nums, k) -
               numSubarraysWithOddAtmost(nums, k - 1);
    }
};