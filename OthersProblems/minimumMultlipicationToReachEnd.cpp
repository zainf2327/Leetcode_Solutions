// User function Template for C++
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        const int INF=1e5;
        bool visited[INF]={false};
        
        queue<pair<int,int>> q;
        q.push({0,start});
        visited[start]=true;
        while(!q.empty())   {
            int curr=q.front().second;
            int cs=q.front().first;
            q.pop();
            if(curr==end) return cs;
            
            for(int& val:arr)    {
                int newVal=(curr*val)%INF;
                if(!visited[newVal]){
                    q.push({cs+1,newVal});
                    visited[newVal]=true;
                }
            }
            
        }
        return -1;
    }
};
