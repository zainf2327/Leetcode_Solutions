#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);
        for(auto &edge: edges)   {
            adj[edge[0]].push_back({edge[1],edge[2]});
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++)    {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty())   {
            int curr=q.front();
            topo.push_back(curr);
            q.pop();
            for(auto &[nei,wt]: adj[curr])    {
                indegree[nei]--;
                if(indegree[nei]==0)    {
                    q.push(nei);
                }
                
            }
        }
        int src=0;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        for(int node:topo)  {
            if(dist[node]!=INT_MAX) {
                 for(auto& [nei,nw]: adj[node])  {
                    if(dist[node]+nw <dist[nei])    {
                        dist[nei]=dist[node]+nw;
                    }
                }
                
            }
           
        }
        for(int& d: dist)   {
            if(d==INT_MAX) d=-1;
        }
        return dist;
        
        
    }
};
