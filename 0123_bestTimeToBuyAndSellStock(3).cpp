#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int d = prices.size();
        int t = 4;
        vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));
        for (int i = d - 1; i >= 0; i--) {
            for (int j = t - 1; j >= 0; j--) {
                if (j % 2) {
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);

                } else {
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
