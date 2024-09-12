#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
private:
    static const int SIZE = 128; // 127 ASCII characters are there
    int count[SIZE] = {0};
public:
    string frequencySort(string s) {
        int n = s.size();
        for (char c : s) {
            count[c]++;
        }
        vector<string> bucket(n + 1);
        for (int i = 0; i < SIZE; i++) {
            if (count[i] == 0)
                continue;
            bucket[count[i]].push_back((char)i);
        }
        string ans = "";
        for (int i = n; i >= 0; i--) {
            for (char c : bucket[i]) {
                ans.append(i, c); // Append 'i' occurrences of character 'c'
            }
        }
        return ans;
    }
};
