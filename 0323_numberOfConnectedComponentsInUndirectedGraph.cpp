#include<vector>
using namespace std;


class Solution {
private:
void dfs(int node, vector<vector<int>>& list,vector<bool>&visited)  {
    visited[node]=true;
    for(int nei: list[node])    {
        if(!visited[nei]){
            dfs(nei,list,visited);
        }
        
    }
}
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //let's do dfs baby 
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
                dfs(i,list,visited);
                count++;
            }
        }
        return count;

    }
};

// TC: O(V+2E(Total degree))
// SC: O(N+N+N)
