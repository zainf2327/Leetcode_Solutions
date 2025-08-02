#include <vector>
using namespace std;

class Solution {
    bool dfs (int node, vector<vector<int>>& graph, vector<int>& state, vector<bool>& isSafe) {
        state[node] = 1;
        for (int nei : graph[node]) {
            if (state[nei] == 0) {
                if (!dfs(nei, graph, state, isSafe)) {
                    state[node] = 2;
                    return false;
                }
            } else if (state[nei] == 1 || state[nei] == 2) {
                state[node] = 2;
                return false;
            }
        }
        state[node] = 3;
        isSafe[node] = true;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> state(
            nodes, 0); // 0 means unvisted,1 means in visited, 2 means visited
                       // and unsafe node ,3 means visited and safe node
        vector<bool> isSafe(nodes, false);
        for (int i = 0; i < nodes; i++) {
            if (state[i] == 0) {
                dfs(i, graph, state, isSafe);
            }
        }
        vector<int> ans;                   // we could have checked through state array as well which nodes are safe if their state is 3
                                
        for (int i = 0; i < nodes; i++) {
            if (isSafe[i])
                ans.push_back(i);
        }
        return ans;
    }
};

// TC:O(N+E+N)
// SC: O(N+N+N+N)