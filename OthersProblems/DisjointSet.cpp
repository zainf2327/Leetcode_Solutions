#include<vector>
#include<algorithm>
using namespace std;

class DisjointSets {
private:
vector<int> parent;
vector<int> rank;
vector<int> size;

public:
DisjointSets(int v) {
    parent.resize(v+1);
    for(int i=0;i<=v;i++)   parent[i]=i;
    rank.resize(v+1,0);
    size.resize(v+1,1);
}
int find(int n) {        // finds the representative of set(root of tree )
    if(parent[n]==n) return n;
    return parent[n]=find(parent[n]);   // path optimization
}
bool isLeader(int node)    {
    return parent[node]=node;
}
bool unionByRank(int u,int v) {     // merge two sets (trees) ,return true otherwise false if they already belong to same set indicating cycle
    int pa=find(u);
    int pb=find(v);
    if(pa==pb) return false;      // u and v already belongs to same set,cannot make union operation,indicates cycle in undirected graph
    if(rank[pa]<rank[pb])   {
        parent[pa]=pb;

    }
    else if(rank[pb]<rank[pa])  {
        parent[pb]=pa;
    }
    else {
        parent[pa]=pb;
        rank[pb]++;
    }
    return true;

}
bool unionBySize(int u,int v) {
    int pa=find(u);
    int pb=find(v);
    if(pa==pb) return false;      // u and v already belongs to same set,cannot make union operation,indicates cycle in undirected graph
    if(size[pa]<size[pb])   {
        parent[pa]=pb;
        size[pb]+=size[pa];
        size[pa]=0;   // indicating that it's not a leader of set

    }
    else {
         parent[pb] = pa;
        size[pa] += size[pb];
        size[pb] = 0; // optional
    }
   
    return true;
}
};


class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int,int>>> edges; // {wt,{u,v}}

        // Extract all edges
        for (int u=0; u<V; u++) {
            for (auto& it : adj[u]) {
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        DisjointSets dj(V);
        int st = 0;

        // Kruskal’s MST
        for (auto& e : edges) {
            int wt = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if (dj.unionBySize(u, v)) {
                st += wt;
            }
        }
        return st;
    }
};
// TC: O(ElogE(for sorting) +Eα(V)(for union function of disjoint class ))
// SC: O(E+2V)