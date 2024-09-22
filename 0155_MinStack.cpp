#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
private:
    stack<int> Stack;
    stack<int> Min;

public:
    MinStack() {}

    void push(int val) {
        Stack.push(val);
        if (Min.empty()) {
            Min.push(val);
        } else {
            int num = min(val, Min.top());
            Min.push(num);
        }
    }

    void pop() {
        Stack.pop();
        Min.pop();
    }

    int top() { 
        return Stack.top(); 
    }

    int getMin() { 
        return Min.top(); 
    }
};