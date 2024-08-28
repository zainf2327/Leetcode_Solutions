#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m)
            return false;
        int seen[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            seen[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (seen[t[i]-'a'] == 0)
                return false;
            seen[t[i]-'a']--;
        }
        return true;
    }
};