#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        for (string& op : operations) {
            if (op == "+") {
                stack.push_back(stack.back() + stack[stack.size() - 2]);
            } else if (op == "D") {
                stack.push_back(2 * stack.back());
            } else if (op == "C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }
        int score = accumulate(stack.begin(), stack.end(), 0);
        return score;
    }
};