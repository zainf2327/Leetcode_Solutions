#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string Stack;
        for (char c : s) {
            if (c == '*') {
                Stack.pop_back();
            } else {
                Stack.push_back(c);
            }
        }
        return Stack;
    }
};