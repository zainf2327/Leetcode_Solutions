#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto & edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())   {
            int curr=q.front();
            q.pop();
            if(curr==destination) return true;
            for(int nei: adj[curr]) {
                if(!visited[nei])   {
                    q.push(nei);
                    visited[nei]=true;
                }
            }
        }
        return false;

        
    }
};