#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        unordered_map<char, char> closeToOpen = {
            {'}', '{'}, {']', '['}, {')', '('}};
        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (stc.empty() || closeToOpen[c] != stc.top()) {
                    return false;
                }
                stc.pop();

            } else {
                stc.push(c);
            }
        }
        return stc.empty();
    }
};