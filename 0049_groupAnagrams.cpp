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
            int count[26] = {0};
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = "";
            for (int c : count) {
                key = key + to_string(c) + "#";
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
