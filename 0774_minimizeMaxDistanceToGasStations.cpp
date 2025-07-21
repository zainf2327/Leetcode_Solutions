#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution  {
private:

int numberOfGasStationsRequired(double maxAllowedDist, const vector<int>& stationPositions) {
    int additionalStations = 0;
    // Iterate over each consecutive pair of existing gas stations
    for (int i = 1; i < stationPositions.size(); i++) {
        // Calculate the gap between the current station and the previous one
         double gap = stationPositions[i] - stationPositions[i - 1];
         
         int numSegments=ceil(gap / maxAllowedDist);  // how many segments are required b/w two stations having dis at most maxAllowedDist
         int  numStations = numSegments-1;          
        additionalStations += numStations;
    }

    return additionalStations;
}

public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        double l=0;
        double h=0;
        for(int i=1;i<arr.size();i++)   {
            double dis=arr[i]-arr[i-1];
            h=max(h,dis);
        }
        double epi =1e-6;
        while(h-l>epi)  {
            double m=(l+h)/2.0;
            if(numberOfGasStationsRequired(m,arr)<=k)   {     // false,false,false .......true
                h=m;
            }
            else l=m;
        }
        return h;
      
    }
};