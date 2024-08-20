#include <iostream>
#include <vector>
using namespace std;
 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
             ans[i].resize(i+1,1);
              for (int j = 1; j < i; j++) {
                    int num = ans[i - 1][j] + ans[i - 1][j - 1];
                    ans[i][j]=num;
              }
        }
        return ans;
    }
};
