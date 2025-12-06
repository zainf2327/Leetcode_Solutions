#include <vector>
#include <string>
using namespace std;
class Solution {

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> pre(m + 1, 0), curr(m + 1, 0);
        pre[0] = 0;
        for (int j = 1; j <= m; j++)
            pre[j] = j;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = pre[j - 1];
                } else
                    curr[j] = 1 + min(curr[j - 1], pre[j]);
            }
            pre = curr;
        }
        return pre[m];
    }
};
//Space Optimization
// TC: O(m*n)
//SC: O(n))