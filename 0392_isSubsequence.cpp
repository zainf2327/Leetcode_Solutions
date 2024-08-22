#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int j = 0, i = 0;
        while (i < n && j < m) {
            if (t[i] == s[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
};
