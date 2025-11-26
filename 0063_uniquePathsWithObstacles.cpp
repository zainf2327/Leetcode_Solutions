#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (!obstacleGrid[0][i])
                dp[i] = 1;
            else
                break;
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                dp[0] = 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j])
                    dp[j] = 0;
                else
                    dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};