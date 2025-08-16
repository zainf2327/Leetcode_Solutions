#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& edge: edges)  {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,0});
        vector<bool> visited(V,false);
        int sum=0;
        while(!q.empty()){
            int node=q.top().second;
            int wt=q.top().first;
            q.pop();
            if(visited[node]) continue;
            visited[node]=true;
            sum+=wt;
            for(auto&[nei,wt]:adj[node])   {
                if(!visited[nei])   {
                    q.push({wt,nei});
                }
            }
        }
        return sum;
    }
};