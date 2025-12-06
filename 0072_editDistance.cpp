#include <string>
#include <vector>
using namespace std;
class Solution {
    int f(string& s, string& t, int i, int j,vector<vector<int>>&dp) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s[i - 1] == t[j - 1])
            return dp[i][j]= f(s, t, i - 1, j - 1,dp);
        else
            return dp[i][j]= 1 + min(f(s, t, i, j - 1,dp),
                           min(f(s, t, i - 1, j,dp), f(s, t, i - 1, j - 1,dp)));
    }

public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1, word2,n ,m,dp);
    }
};

// Memoization
//O(n*m)