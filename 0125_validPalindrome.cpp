#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        while (r < n) {
            if (isalnum(s[r])) {
                s[l] = tolower(s[r]);
                l++;
            }
            r++;
        }
        r = l - 1;
        l = 0;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};