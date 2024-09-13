#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& str : strs) {
            string x = str;
            sort(x.begin(), x.end());
            map[x].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};