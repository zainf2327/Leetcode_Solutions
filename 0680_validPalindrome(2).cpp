#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    bool ispalindrome(string& s, int l, int r, int deleted, int maxDeletion) {
        if (deleted > maxDeletion)
            return false;
        while (l < r) {
            if (s[l] != s[r]) {
                return ispalindrome(s, l + 1, r, deleted + 1, maxDeletion) ||
                       ispalindrome(s, l, r - 1, deleted + 1, maxDeletion);
            }
            l++;
            r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        return ispalindrome(s, 0, s.size() - 1, 0, 1);
    }
};
