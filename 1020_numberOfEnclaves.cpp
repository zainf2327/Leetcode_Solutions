#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (grid[0][i]) {
                q.push({0, i});
                grid[0][i] = 0;
            }
            if (grid[n - 1][i]) {
                q.push({n - 1, i});
                grid[n - 1][i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0]) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if (grid[i][m - 1]) {
                q.push({i, m - 1});
                grid[i][m - 1] = 0;
            }
        }
        int dir[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = cr + dir[i];
                int nc = cc + dir[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        int enclaves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                enclaves += grid[i][j];
            }
        }
        return enclaves;
    }
};