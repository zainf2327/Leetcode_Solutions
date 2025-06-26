#include <vector>
using namespace std;
class Solution
{
public:
   int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, l = 0, n = nums.size(), zeros = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
