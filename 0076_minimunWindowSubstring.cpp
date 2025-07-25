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

        for (int i = 0; i < n; i++) {
            int hash[256] = {0};
            int count = 0;
            for (int k = 0; k < m; k++)
                hash[t[k]]++;
            for (int j = i; j < n; j++) {
                if (hash[s[j]] > 0)
                    count++;
                hash[s[j]]--;
                if (count == m) {
                    if (minLength > (j - i + 1)) {
                        minLength = j - i + 1;
                        strInd = i;
                    }
                    break;
                }
            }
        }
        return (strInd == -1) ? "" : s.substr(strInd, minLength);
    }
};