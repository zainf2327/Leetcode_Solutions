#include <vector>
using namespace std ;
class Solution {
    int f(int i, int tranNum, int n, vector<int>& prices,
          vector<vector<int>>& dp) {
        if (i >= n || tranNum >= 2)
            return 0;
        if (dp[i][tranNum] != -1)
            return dp[i][tranNum];
        if (tranNum == 0) {
            int buy = -prices[i] + f(i + 1, 1, n, prices, dp);
            int notBuy = f(i + 1, 0, n, prices, dp);
            return dp[i][tranNum] = max(buy, notBuy);
        }

        int sell = prices[i] + f(i + 1, 2, n, prices, dp);
        int notSell = f(i + 1, 1, n, prices, dp);
        return dp[i][tranNum] = max(sell, notSell);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 0, n, prices, dp);
    }
};

// Memoization Solution 
// TC: n*2
//SC: O(n)(call stack)  +  O(n*2)