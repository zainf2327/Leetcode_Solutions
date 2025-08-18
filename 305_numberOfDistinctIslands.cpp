#include<vector>
using namespace std;
class DisjointSet {
private:
vector<int> parent;
vector<int> size;

public:
DisjointSet(int v) {
    parent.resize(v+1);
    for(int i=0;i<=v;i++)   parent[i]=i;
    size.resize(v+1,1);
}
int find(int n) {        // finds the representative of set(root of tree )
    if(parent[n]==n) return n;
    return parent[n]=find(parent[n]);   // path optimization
}
bool isLeader(int node)    {
    return parent[node]==node;
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<bool>> grid(n,vector<bool>(m,false)); //intially all cells are filled with water
        int numComponents=0;
        DisjointSet ds(n*m);
        vector<int> ans;
        int dir[]={-1,0,1,0,-1};
        
        for(auto& it:operators)   {
            int r=it[0];
            int c=it[1];
            if(grid[r][c]) {
                ans.push_back(numComponents);
                continue;
            }
            grid[r][c]=1;
            int curr=r*m+c;
            numComponents++;
            for(int i=0;i<5;i++)    {
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                int nei=nr*m+nc;
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]&& ds.unionBySize(curr,nei))   {
                    numComponents--;
                }
                
            }
            ans.push_back(numComponents);
            
        }
        return ans;
    }
};
