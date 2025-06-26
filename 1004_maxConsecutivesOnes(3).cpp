#include <vector>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0, n = nums.size();

        for (int l = 0; l < n; l++)
        {
            int zeros = 0;

            for (int r = l; r < n; r++)
            {
                if (nums[r] == 0)
                    zeros++;

                if (zeros > k)
                    break;

                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen;
    }
};
