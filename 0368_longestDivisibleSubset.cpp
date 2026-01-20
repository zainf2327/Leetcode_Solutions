#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }
        int k = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[k]) {
                k = i;
            }
        }
        vector<int> lds;
        while (k != -1) {
            lds.push_back(nums[k]);
            k = pre[k];
        }
        return lds;
    }
};

// If any num is divisible by largest number in currently chosen subsequence/subset, then only we can surely say that curr num would be divisible by all nums in curr subsequece. For this we need to sort the array
//nums = [2, 6, 3] like this example in this if we donot sort the array it would dp[2]=3 that's wrong