#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                stc.push(c);
            } else {
                if (stc.empty() || c == ']' && stc.top() != '[' ||
                    c == '}' && stc.top() != '{' ||
                    c == ')' && stc.top() != '(') {
                    return false;
                }
                stc.pop();
            }
        }
        return stc.empty();
    }
};