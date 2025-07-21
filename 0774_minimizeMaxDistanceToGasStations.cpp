# include <vector>
using namespace std;

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        int howManyPlaced[n-1]={0};
        
        for(int i=1;i<=k;i++)   {
            int maxSectionLength=0;
            int maxSectionIndex=-1;
            for(int j=0;j<n-1;j++)  {
                int diff=stations[j+1]-stations[j];
                double sectionLength=(double) diff/(1+howManyPlaced[j]);
                if(sectionLength>maxSectionLength)  {
                    maxSectionLength=sectionLength;
                    maxSectionIndex=j;
                }
            }
            
            howManyPlaced[maxSectionIndex]++;
        }
        double maxDistance=0;
        
    
        for(int j=0;j<n-1;j++)  {
                int diff=stations[j+1]-stations[j];
                double sectionLength=(double) diff/(1+howManyPlaced[j]);
                maxDistance=max(maxDistance,sectionLength);
        }
        return maxDistance;
    }
};