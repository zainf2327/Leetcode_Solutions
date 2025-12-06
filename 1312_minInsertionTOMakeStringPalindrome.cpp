#include <string>
#include<vector>
using namespace std;
class Solution {
int f(int i,int j,string& s,vector<vector<int>>&dp)    {
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j])
        return dp[i][j]= f(i+1,j-1,s,dp);
    else 
        return dp[i][j]=1+min(f(i+1,j,s,dp),f(i,j-1,s,dp));
}
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int l=2;l<=n;l++)  {
            for(int i=0;i<=n-l;i++)    {
                int j=i+l-1;
                if(s[i]==s[j])  dp[i][j]= dp[i+1][j-1];
                else dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        } 
        return dp[0][n-1];
    }
};