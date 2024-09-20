#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        for (string& token : tokens) {
            if (token == "+") {
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                Stack.push(a + b);
            } else if (token == "-") {
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                Stack.push(a - b);
            } else if (token == "*") {
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                Stack.push(a * b);
            } else if (token == "/") {
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                Stack.push(a / b);
            } else {
                Stack.push(stoi(token));
            }
        }
        return Stack.top();
    }
};