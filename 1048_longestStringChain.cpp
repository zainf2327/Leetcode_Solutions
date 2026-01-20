#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
    bool static comparator(string& a, string& b) { return a.size() < b.size(); }
    bool ispredecessor(string& a, string& b) { // check a is predecessor of b
        int n = a.size();
        int m = b.size();
        if (n + 1 != m)
            return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == n;
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] + 1 > dp[i] && ispredecessor(words[j], words[i])) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};