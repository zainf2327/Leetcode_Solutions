#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int score = 0;
        for (int i = 0; i < n - 1; i++) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};
