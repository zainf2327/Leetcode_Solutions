#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = 0;
        int l = 0, r = 0;
        bool Set[256] = {false};

        while (r < n) {
            while (Set[s[r]]) {
                Set[s[l]] = false;
                l++;
            }
            Set[s[r]] = true;  
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
