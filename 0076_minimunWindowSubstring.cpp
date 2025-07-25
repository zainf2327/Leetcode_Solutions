#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        // we have to find minlength(as well as starting index) of substring
        // that have atleast characters of t
        int n = s.size();
        int m = t.size();
        int minLength = INT_MAX;
        int strInd = -1;
        int l = 0, r = 0;
        int hash[256] = {0};
        for (int i = 0; i < m; i++)
            hash[t[i]]++;
        int count = 0;
        while (r < n) {
            hash[s[r]]--;
            if (hash[s[r]] >= 0)
                count++;
            while (count == m) {
                if (minLength > (r - l + 1)) {
                    minLength = r - l + 1;
                    strInd = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }

        return (strInd == -1) ? "" : s.substr(strInd, minLength);
    }
};