#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,0);
        for(int j=0;j<n;j++)    {    //First row
            dp[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)    {   // Remaining Rows
            vector<int>curr(n);
            curr[0]=matrix[i][0]+min(dp[0],dp[1]);    // Fast column
            for(int j=1;j<n-1;j++)  {                 // Remaining column
                curr[j]=matrix[i][j]+min(dp[j-1],min(dp[j],dp[j+1])); 
            }
            curr[n-1]=matrix[i][n-1]+min(dp[n-1],dp[n-2]);    // Last column
            dp=curr;
        } 
        int ans=dp[0];
        for(int j=1;j<n;j++)    {
            ans=min(ans,dp[j]);
        }
        return ans;
        

        
    }
};