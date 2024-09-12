#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
private:
    unordered_map<char, int> count;
public:
    string frequencySort(string s) {
        for (char c : s) {
            count[c]++;
        }
        auto comparator = [this](char a, char b) -> bool {
            if (count[a] != count[b])
                return count[a] > count[b];
            return a < b;
        };
        sort(s.begin(), s.end(), comparator);

        return s;
    }
};
