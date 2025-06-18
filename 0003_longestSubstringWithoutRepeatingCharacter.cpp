#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),maxLen=0;
        for (int l = 0; l < n; l++) {
            bool seen[256]={0};
            for (int r = l; r < n; r++) {
                if(seen[s[r]])   break;
                maxLen=max(r-l+1,maxLen);
                seen[s[r]]=true;
            }
        }
        return maxLen;
    }
};