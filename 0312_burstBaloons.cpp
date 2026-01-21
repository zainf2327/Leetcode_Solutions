#include<vector>
#include <algorithm>
using namespace std;
class Solution {
int f(int i, int j, vector<int>& nums) {
        if (i > j || j == i + 1)
            return 0;
        int coins = 0;
        for (int k = i + 1; k < j; k++) {
            coins =
                max(coins, f(i, k, nums) + f(k, j, nums) + (nums[i]*nums[k]*nums[j]));
        }
        return coins;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 1; l < n - 1; l++) {
            for (int i = 0; i + l + 1 < n; i++) {
                int j = i + l + 1;
                dp[i][j] = 0;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                                 (nums[i] * nums[k] * nums[j]));
                }
            }
        }

        return dp[0][n - 1];
    }
};