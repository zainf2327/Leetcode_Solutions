#include<vector>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c, int drow[], int dcol[]) {
        int rows = grid.size();
        int cols = grid[0].size();
        grid[r][c] = '0'; // mark them as visited
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                grid[nr][nc] == '1') {
                dfs(grid, nr, nc, drow, dcol);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, drow, dcol);
                    count++;
                }
            }
        }
        return count;
    }
};


//TC: O(n*m*4)
// SC:O(n*m+4)