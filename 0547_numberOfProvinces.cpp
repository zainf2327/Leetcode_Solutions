#include <vector>
#include <queue>
using namespace std;

class Solution {
    void bfs(int node, vector<vector<int>>& matrix, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        int n = matrix.size();
        while(!q.empty()) {
            int curr=q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (matrix[curr][i] && !visited[i]) {
                    q.push(i);
                    visited[i]=true;
                }
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
                bfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};

// TC: O(n + n*n)
// SC: O(n+n)