#include <vector>
using namespace std ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0, n = prices.size();
        int l = 0, r = 0;
        while (r < n) {
            if (prices[r] >= prices[l]) {
                int profit = prices[r] - prices[l];
                maxPro = max(maxPro, profit);
            } else
                l = r;

            r++;
        }
        return maxPro;
    }
};