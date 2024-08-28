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
        unordered_map<int, int> seen;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (!seen.count(t[i]) || seen[t[i]] == 0)
                return false;
            seen[t[i]]--;
        }
        return true;
    }
};