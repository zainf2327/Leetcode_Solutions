#include<string>
#include <vector>
using namespace std;
class Solution {
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, string& s) {
        if (i == n - 1)
            return 0;
        int minCuts = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(i, k, s)) {
                minCuts = min(minCuts, f(k + 1, n, s));
            }
        }
        return minCuts;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            isPal[i][i] = true;
        }

        for (int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for (int k = i; k < n; k++) {
                if (s[i] == s[k] && (k - i < 2 || isPal[i + 1][k - 1])) {
                    isPal[i][k] = true;
                    if (k == n - 1) {
                        minCuts = 0;
                    } else {
                        minCuts = min(minCuts, 1 + dp[k + 1]);
                    }
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
};