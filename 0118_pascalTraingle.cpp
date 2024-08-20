#include <iostream>
#include <vector>
using namespace std;
 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    ans[i].push_back(1);
                } else {
                    int num = ans[i - 1][j] + ans[i - 1][j - 1];
                    ans[i].push_back(num);
                }
            }
        }
        return ans;
    }
};
