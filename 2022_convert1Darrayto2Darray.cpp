#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};
        }
        int ptr = 0;
        vector<vector<int>> grid;
        for (int i = 0; i < m; i++) {
            grid.push_back(vector<int>(n));
            for (int j = 0; j < n; j++) {
                grid[i][j]=original[i*n+j];
            }
        }
        return grid;
    }
};