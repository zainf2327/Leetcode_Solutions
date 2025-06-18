#include <vector>
using namespace std ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0,n=prices.size();
        for(int l=0;l<n;l++)    {
            for(int r=l+1;r<n;r++)  {
                int profit=prices[r]-prices[l];
                maxPro=max(maxPro,profit);
            }
        }
        return maxPro;
        
    }
};