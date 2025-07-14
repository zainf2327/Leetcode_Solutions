# include <vector>
# include <algorithm>
using namespace std;

class Solution {
    private:
    bool isValid(vector<int>& stalls,int numCows,int dis)   {
        int cowsPlaced=1;
        int lastPos=stalls[0];
        for(int i=1;i<stalls.size();i++)    {
            if(stalls[i]-lastPos>=dis)  {
                cowsPlaced++;
                lastPos=stalls[i];
                if(cowsPlaced==numCows) return true;
            }
        }
        return false;
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        if(k>n) return -1;
        sort(stalls.begin(),stalls.end());
        int l=1;
        int r=stalls[n-1]-stalls[0];
        while(l<=r) {
            int m=(l+r)/2;
            if(isValid(stalls,k,m)) {
                l=m+1;
            }
            else r=m-1;
        }
        return r;
        
    }
};