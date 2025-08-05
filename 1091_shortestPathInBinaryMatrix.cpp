#include<vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
                    return -1;
        q.push({{0, 0}, 1});
        grid[0][0] = 1; // mark it as visited
        while (!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cd = q.front().second ;
            q.pop();
            if (cr == n - 1 && cc == m - 1)
                return cd;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nr = cr + i;
                    int nc = cc + j;
                    if (nr >= 0 && nr < n && nc >= 0&& nc < m && grid[nr][nc] == 0 ) {
                        q.push({{nr, nc}, cd + 1});
                        grid[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};