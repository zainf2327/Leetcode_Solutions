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
        int buyNext=0,sellNext=0;
        for (int i = n - 1; i >= 0; i--) {
            int buy=max(buyNext,-prices[i]+sellNext);
            int sell = max(sellNext, prices[i]+0);
            buyNext=buy;
            sellNext=sell;
        }
        return buyNext;
    }
};

// Space Optimization  
// TC: n
//SC: O(2)