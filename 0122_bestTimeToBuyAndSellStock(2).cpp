#include <vector>
using namespace std;

class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int d = prices.size();
        vector<vector<int>> dp(d + 1, vector<int>(3, 0));
        for (int i = d - 1; i >= 0; i--) {
            dp[i][1] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);

            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        return dp[0][0];
    }
};
