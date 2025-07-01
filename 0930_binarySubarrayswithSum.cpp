# include <vector>
using namespace std;
class Solution {
private:
    int numSubarraysWithSumAtmost(vector<int>& nums, int target) {
        if (target < 0)
            return 0;
        int count = 0;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum = sum + nums[r];
            while (sum > target) {
                sum = sum - nums[l];
                l++;
            }

            count = count + (r - l + 1);
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return numSubarraysWithSumAtmost(nums, goal) -
               numSubarraysWithSumAtmost(nums, goal - 1);
    }
};