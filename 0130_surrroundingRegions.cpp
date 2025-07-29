#include<vector>
using namespace std;
class Solution {
private:
    bool isEdge(int r, int c, int n, int m) {
        return (r - 1) < 0 || (r + 1) >= n || (c - 1) < 0 || (c + 1) >= m;
    }
    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<bool>>& visited, int dir[]) {
        int n = board.size();
        int m = board[0].size();
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == 'O' && !visited[nr][nc]) {
                dfs(nr, nc, board, visited, dir);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isEdge(i, j, n, m) && board[i][j] == 'O' &&
                    !visited[i][j]) {
                    dfs(i, j, board, visited, dir);
                }
            }
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// TC: O(N*M+N*M*4)
// SC: O(N*M+N*M)