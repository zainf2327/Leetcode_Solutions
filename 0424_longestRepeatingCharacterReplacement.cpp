# include <string>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int hash[26] = {0};
            int maxfre = 0;
            for (int j = i; j < s.size(); j++) {
                hash[s[j] - 'A']++;
                maxfre = max(maxfre, hash[s[j] - 'A']);
                int currlen = j - i + 1;
                if (currlen - maxfre <= k) {
                    maxLen = max(maxLen, currlen);
                }
            }
        }
        return maxLen;
    }
};