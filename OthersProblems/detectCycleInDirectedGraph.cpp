#include <vector>
#include <queue>
using namespace std;

class Solution {
     bool detectCycleWithDFS(vector<vector<int>>& adj, vector<bool>& visited, int curr,int parent) {
        visited[curr] = true;
        for(auto nei: adj[curr]) {
            if(!visited[nei]) {
                if(detectCycleWithDFS(adj,visited,nei,curr)) return true;
            }
            else {
                if(parent!=nei) return true;
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
                if (detectCycleWithDFS(adj, visited, i,-1))
                    return true;
            }
        }
        return false;
    }
};


// TC: O(N+N+2E)     // 2E means total degree of undirected graph
// SC: O(N+N+(N+2E))