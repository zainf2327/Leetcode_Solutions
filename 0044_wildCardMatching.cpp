#include <string>
#include <vector>
using namespace std;

// class Solution {
//     bool areAllStars(int j, string& p) {
//         while (j >= 0) {
//             if (p[j] != '*')
//                 return false;
//             j--;
//         }
//         return true;
//     }
//     bool f(int i, int j, string& s, string& p) {
//         if (i < 0 && j < 0)
//             return true;
//         if (i < 0 && j >= 0)
//             return areAllStars(j, p);
//         if (i >= 0 && j < 0)
//             return false;

//         if (p[i] == '?' || s[i] == p[j]) {
//             return f(i - 1, j - 1, s, p);
//         } else if (p[j] == '*') {
//             return f(i, j - 1, s, p) || f(i - 1, j, s, p);
//         }
//         return false;
//     }

// public:
//     bool isMatch(string s, string p) {
//         int i = s.size(), j = p.size();
//         return f(i - 1, j - 1, s, p);
//     }
// };
class Solution {

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] != '*')
                break;
            dp[0][j] = true;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};