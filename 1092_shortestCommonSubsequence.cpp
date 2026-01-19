#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {

public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e4));
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string scs;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                scs.push_back(a[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    scs.push_back(a[i - 1]);
                    i--;
                } else {
                    scs.push_back(b[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0) {
            scs.push_back(a[i - 1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(b[j - 1]);
            j--;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
};