#include<vector>
#include <algorithm>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>& cuts) {
        if (i > j || j == i + 1)
            return 0;
        int cost = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            cost =
                min(cost, f(i, k, cuts) + f(k, j, cuts) + (cuts[j] - cuts[i]));
        }
        return cost;
    }

public:
   //dp[i][j] reprensts minimum cost to cut stick of boundaries [cuts[i].....cuts[j]] such that possible cuts are from [cuts[i+1]....cuts[j-1]]
   //dp[0][5] represts minimum cost to cut stick of boundaries [cuts[0](0).....cuts[5](7)] such that possible cuts are from [cuts[1]....cuts[4]] 
   int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // numCuts = number of cuts between i and j
        for (int numCuts = 1; numCuts < m - 1; numCuts++) {
            for (int i = 0; i + numCuts + 1 < m; i++) {
                int j = i + numCuts + 1;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                }
            }
        }

        return dp[0][m - 1];
    }
};
