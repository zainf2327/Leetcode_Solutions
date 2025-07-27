#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<pair<int, int>, int>> q;     //{{r,c},dist}
        int countFresh = 0;
        int minTime = 0;
        int drow[] = {0, -1, 0, 1};          // each node has four adjacent neighbours 
        int dcol[] = {-1, 0, 1, 0};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});     //  adding rotten oranges into queue as starting point with dist 0
                }

                else if (grid[i][j] == 1)
                    countFresh++;
            }
        }

        while (!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cd = q.front().second;
            q.pop();
            minTime = max(minTime, cd);
            for (int i = 0; i < 4; i++) { 
                int nr = cr + drow[i];
                int nc = cc + dcol[i];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c &&
                    grid[nr][nc] == 1) {
                    countFresh--;
                    q.push({{nr, nc}, cd + 1});
                    grid[nr][nc] = 2;        // mark the fresh orange rotten just like visited
                }
            }
        }
        return (countFresh == 0) ? minTime : -1;
    }
};

// TC: O(m*n + m*n *4))
// SC: O(m*n)