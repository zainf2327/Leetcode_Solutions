#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // multi source bfs
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue <pair<pair<int, int>,int>> q; // {r,c},dis
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(mat[i][j]==0) {
                    q.push({{i, j}, 0}); // staring from all 0 with distance 0
                    dist[i][j]=0;
                    visited[i][j]=true;
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cd = q.front().second;
            q.pop();
            dist[cr][cc] = cd;
            for (int i = 0; i < 4; i++) {
                int nr = cr + drow[i];
                int nc = cc + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc])  {
                    q.push({{nr, nc}, cd + 1});
                    visited[nr][nc]=true;
                }
            }
        }
        return dist;
    }
};