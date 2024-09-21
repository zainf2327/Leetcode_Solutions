#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] == '*') {
                l--;
            } else {
                s[l] = s[r];
                l++;
            }
        }
        s.resize(l);
        return s;
    }
};