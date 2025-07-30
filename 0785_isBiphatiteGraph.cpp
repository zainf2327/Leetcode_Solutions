#include <vector>
using namespace std;
class Solution {
    bool dfs(int node, vector<vector<int>> & graph, vector<int>& color) {
        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                color[nei] = !color[node];
                if (!dfs(nei, graph, color))
                    return false;
            } else {
                if (color[node] == color[nei])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1) ; // use it as visited array and as well as array to hold the color of each node 0 meean  red and 1 means black

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};

// O(V+V+E)
// O(V+V)
// acylic graph or graph having cycle containg even number of nodes is biphatite
// graph having cylce containing odd number of nodes is not biphatite