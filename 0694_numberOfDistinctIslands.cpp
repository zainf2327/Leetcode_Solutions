// User function Template for C++
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
  private:
  void bfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& visited, vector<pair<int,int>>& res)  {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c]=true;
    int dir[]={-1,0,1,0,-1};
    while(!q.empty())   {
        int cr=q.front().first;
        int cc=q.front().second;
        res.push_back({cr-r,cc-c});
        q.pop();
        for(int i=0;i<4;i++)    {
            int nr=cr+dir[i];
            int nc=cc+dir[i+1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] &&!visited[nr][nc]) {
                q.push({nr,nc});
                visited[nr][nc]=true;
                
            }
        }
    }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)    {
            for(int j=0;j<m;j++)    {
                if(grid[i][j] == 1 && !visited[i][j])  {
                    vector<pair<int,int>> res;
                    bfs(i,j,grid,visited,res);
                    st.insert(res);
                }
            }
        }
        return st.size();
    }
};


