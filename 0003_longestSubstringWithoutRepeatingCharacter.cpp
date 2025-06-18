#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLen = 0;
        int l = 0, r = 0;
        int hashMap[256] = {-1};            // char to index mapping
        for (int i = 0; i < 256; i++)
            hashMap[i] = -1;

        while (r < n) {
            if (hashMap[s[r]] != -1 && hashMap[s[r]] >= l) {     // if  char is in curr substring
                l = hashMap[s[r]] + 1;                           // move left pointer to one step ahead of current character previous occurance
            }
            hashMap[s[r]] = r;                                  // update char latest position
            maxLen = max(maxLen, r - l + 1);                    //update max length
            r++;
        }

        return maxLen;
    }
};
