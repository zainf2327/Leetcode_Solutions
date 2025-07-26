#include<vector>
#include <queue>
using namespace std;


class Solution {
private:
void bfs(int node, vector<vector<int>>& list,vector<bool>&visited)  {
    queue <int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()) {
        int curr=q.front();
        q.pop();
        for(int neighbour: list[curr])   {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour]=true;
            }
        }
    }
}
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //let's do bfs baby
        vector<vector<int>> list(n);
        for(auto& edge:edges) {
            int n1=edge[0];
            int n2=edge[1];
            list[n1].push_back(n2);
            list[n2].push_back(n1);
        }
        int count=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)    {
            if(!visited[i]) {
                bfs(i,list,visited);
                count++;
            }
        }
        return count;

    }
};


// TC: O(V+2E(total degree))
// SC : O(N+N+N)