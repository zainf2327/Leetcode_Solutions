#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state,
             vector<int>& ans) {
        state[node] = 1;
        for (int nei : graph[node]) {
            if (state[nei] == 0) {
                if (!dfs(nei, graph, state, ans)) {
                    state[node] = 2;
                    return false;
                }
            } else if (state[nei] == 1 || state[nei] == 2) {
                state[node] = 2;
                return false;
            }
        }
        state[node] = 3;
        ans.push_back(node);
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> state(
            nodes, 0); // 0 means unvisted,1 means in visited, 2 means visited
                       // and unsafe node ,3 means visited and safe node
        vector<int> ans;
        for (int i = 0; i < nodes; i++) {
            if (state[i] == 0) {
                dfs(i, graph, state, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// TC:O(N+E+Nlogn)
// SC: O(N+N+N)