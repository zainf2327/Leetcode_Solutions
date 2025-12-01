#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to generate all parenthesizations
    vector<pair<string,int>> solve(vector<int>& arr, int i, int j) {
        vector<pair<string,int>> res;

        // Base case: single matrix
        if (i == j) {
            res.push_back({ "A" + to_string(i), 0 });
            return res;
        }

        // Try all possible splits
        for (int k = i; k < j; k++) {
            vector<pair<string,int>> left = solve(arr, i, k);
            vector<pair<string,int>> right = solve(arr, k+1, j);

            for (auto &L : left) {
                for (auto &R : right) {
                    string parenth = "(" + L.first + " x " + R.first + ")";
                    int cost = L.second + R.second + arr[i-1]*arr[k]*arr[j];
                    res.push_back({ parenth, cost });
                }
            }
        }
        return res;
    }

    // Generate all parenthesizations and return them
    vector<pair<string,int>> generateAll(vector<int>& arr) {
        return solve(arr, 1, arr.size()-1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};

    auto results = sol.generateAll(arr);

    cout << "All possible parenthesizations with costs:\n";
    for (auto &p : results) {
        cout << p.first << " => cost = " << p.second << "\n";
    }

    return 0;
}

