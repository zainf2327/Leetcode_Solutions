#include <vector>
#include <climits>
#include <queue>
using namespace std;
class Solution {   // First version using visited array no further same node can be added to queue once it has been processed  using (cd+nw)<dist[nei] since first time node has been processed it's at shortest path from source and the visited array ensures that while same nodes are in queue,first node is now processed with shortest distance so same nodes that was in already queue just donot  being processed
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& edge: edges)  {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>dist(V,INT_MAX);
        vector<bool> visited(V,false);
        dist[src]=0;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
       pq.push({0,src});
       while(!pq.empty())   {
           int curr=pq.top().second;
           int cd=pq.top().first;
           pq.pop();
           if(visited[curr]) continue;
           visited[curr]=true;
           
           for(auto &[nei,nw]: adj[curr]) {
               if(!visited[nei] && (dist[curr]+nw)<dist[nei]) {
                   dist[nei]=dist[curr]+nw;
                   pq.push({dist[nei],nei});
               }
           }
           
           
       }
       return dist;
    }
};


class Solution {     // Second version using outdated chek no further same node can be added to queue once it has been processed  using (cd+nw)<dist[nei] since first time node has been processed it's at shortest path from source and outdated check ensures that while same nodes are in queue,first node is now processed with shortest distance so same nodes that was in already queue just donot being processed
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& edge: edges)  {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>dist(V,INT_MAX);
        vector<bool> visited(V,false);
        dist[src]=0;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
       pq.push({0,src});
       while(!pq.empty())   {
           int curr=pq.top().second;
           int cd=pq.top().first;
           pq.pop();
           if(cd>dist[curr]) continue;
           
           for(auto &[nei,nw]: adj[curr]) {
               if((dist[curr]+nw)<dist[nei]) {
                   dist[nei]=cd+nw;
                   pq.push({dist[nei],nei});
               }
           }
           
           
       }
       return dist;
    }
};