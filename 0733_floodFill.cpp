#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int inColor = image[sr][sc];
        if (inColor == color)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int drow[] = {0, -1, 0, 1}; // each node has four adjacent neighbours
        int dcol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + drow[i];
                int nc = cc + dcol[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    image[nr][nc] == inColor) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};


// TC: O(N*M*4)
// SC: O(N*M)