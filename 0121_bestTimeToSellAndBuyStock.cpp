#include <vector>
using namespace std ;
class Solution {
int f(int i,int tranNum,int n,vector<int>&prices)    {
    if(i>=n || tranNum>=2) return 0;
    if(tranNum==0)  {
        int buy=-prices[i]+f(i+1,1,n,prices);
        int notBuy=f(i+1,0,n,prices);
        return max(buy,notBuy);
    }
    
        int sell=prices[i]+f(i+1,2,n,prices);
        int notSell=f(i+1,1,n,prices);
        return max(sell,notSell);

}
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,0,n,prices);
        
    }
};

// recursive Solution TC: 2^n
//SC: O(n) call stack +O(2^n)