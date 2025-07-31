#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st) {
        state[node] = 1; // in visiting
        for (int nei : adj[node]) {
            if (state[nei] == 0) {
                if (!dfs(nei, adj, state, st))
                    return false;
            } else if (state[nei] == 1)
                return false; // back edge(cycle)
        }
        state[node] = 2; // visited
        st.push(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> state(numCourses,0);            // 0: unvisited, 1: visiting, 2: visited
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state, st))
                    return {};
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};