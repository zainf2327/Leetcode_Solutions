#include <vector>
using namespace std;

class Solution {
    bool cycleDetectionWithDFS(int node, vector<vector<int>>& adj,
                               vector<int>& state) {
        state[node] = 1; // visiting
        for (int nei : adj[node]) {
            if (state[nei] == 0) { // unvisited
                if (cycleDetectionWithDFS(nei, adj, state))
                    return true;
            } else if (state[nei] == 1) { // back edge found
                return true;
            }
        }
        state[node] = 2; // visited
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> state(numCourses,
                          0); // 0 = unvisited, 1 = visiting, 2 = visited

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (cycleDetectionWithDFS(i, adj, state))
                    return false; // cycle found
            }
        }
        return true; // no cycles, all courses can be completed
    }
};
