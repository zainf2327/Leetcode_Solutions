#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxFre = 0;
        int l = 0;
        int hash[26] = {0};

        for (int r = 0; r < s.size(); r++) {
            hash[s[r] - 'A']++;
            maxFre = max(maxFre, hash[s[r] - 'A']);
            int currLen = r - l + 1;

            if (currLen - maxFre > k) {
                hash[s[l] - 'A']--;
                l++;
            } else {
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};

