#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int d = prices.size();
        int t = k * 2;
        vector<int> dp(t + 1, 0);
        for (int i = d - 1; i >= 0; i--) {
            for (int j = 0; j < t; j++) {
                if (j % 2) {
                    dp[j] = max(prices[i] + dp[j + 1], dp[j]);

                } else {
                    dp[j] = max(-prices[i] + dp[j + 1], dp[j]);
                }
            }
        }
        return dp[0];
    }
};
