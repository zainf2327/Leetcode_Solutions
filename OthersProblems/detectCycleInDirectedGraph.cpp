#include <vector>
#include <queue>
using namespace std;

class Solution {
    bool detectCycle(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        queue<pair<int, int>> q;  // node, parent
        q.push({node, -1});
        visited[node] = true;

        while (!q.empty()) {
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto nei : adj[curr]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, curr});
                } else if (nei != par) {
                    return true;  // Cycle found
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(V,false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(adj, visited, i))
                    return true;
            }
        }
        return false;
    }
};
