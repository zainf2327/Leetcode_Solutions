#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int l = 0, r = mat.size(); // binary search on rows
        while (l <= r) {
            int m = (l + r) / 2;
            int c = max_element(mat[m].begin(), mat[m].end()) - mat[m].begin();
            int top = (m - 1 >= 0) ? mat[m - 1][c] : -1;
            int bottom = (m + 1 < rows) ? mat[m + 1][c] : -1;
            if (mat[m][c] > top && mat[m][c] > bottom) {
                return {m, c};
            } else if (mat[m][c] < top) {
                r = m - 1;
            } else
                l = m + 1;
        }
        return {-1, -1};
    }
};