#include<vector>
#include<algorithm>
using namespace std;
class Solution{
private:
bool isValid(vector<vector<int>>&matrix,int place,int element)  {
    int r=matrix.size();
    int c=matrix[0].size();
    int count=0;
    for(int i=0;i<r;i++)    {
        int fre=upper_bound(matrix[i].begin(),matrix[i].end(),element)-matrix[i].begin();
        count+=fre;
        if(count>=place) return true;
    }
    return false;
}
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int place=(n*m +1)/2;   // position of median in sorted array (1-based indexing)
        // false,false,false,false ......... true , true , true     // find first true 
        //we have to find first element such that elements less than or equal to it is greater than or equal to median position
        int l=INT_MAX;
        int r=INT_MIN;
        for(int i=0;i<n;i++)    {
            l=min(l,matrix[i][0]);
            r=max(r,matrix[i][m-1]);
        }
         while(l<=r) {
            int m=l+(r-l)/2;
            if(isValid(matrix,place,m)) {
                r=m-1;
            }
            else l=m+1;
        }
        return l;
    }
};