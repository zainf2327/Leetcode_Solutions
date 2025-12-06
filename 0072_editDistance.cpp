#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> pre(m+1,0);
        pre[0] = 0;
        for (int j = 1; j <= m; j++)
            pre[j] = j;
        for (int i = 1; i <= n; i++) {
            vector<int>curr(m+1,0);
            curr[0]=i;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = pre[j - 1];
                else
                    curr[j] = 1 + min(curr[j - 1],min(pre[j], pre[j - 1]));
            }
            pre=curr;
        }
        return pre[m];
    }
};
//Space Optimization
// O(n*m) for time and O(m) for space