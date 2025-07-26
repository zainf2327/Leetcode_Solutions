#include <vector>
using namespace std;

class Solution {
    void dfs(int node, vector<vector<int>>& matrix, vector<bool>& visited) {
        visited[node] = true;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            if (matrix[node][i] && !visited[i]) {
                dfs(i, matrix, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};


// TC: O(n + n*n)
// SC: O(n+n)