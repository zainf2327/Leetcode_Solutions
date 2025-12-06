#include <string>
#include <vector>
using namespace std;
class Solution {
    int f(string& s, string& t, int i, int j) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (s[i - 1] == t[j - 1])
            return f(s, t, i - 1, j - 1);
        else
            return 1 + min(f(s, t, i, j - 1),                           // insert,delete,replace
                           min(f(s, t, i - 1, j), f(s, t, i - 1, j - 1)));
    }

public:
    int minDistance(string word1, string word2) {
        return f(word1, word2, word1.size(), word2.size());   //O(3^(n+m))
    }
};