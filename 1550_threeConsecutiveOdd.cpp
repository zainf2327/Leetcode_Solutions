#include <vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        int n=arr.size(),consOdds=0;
        for(int i=0;i<n;i++)  {
            if(arr[i]%2==1) {
                consOdds++;
                if(consOdds==3) return true;
            }
            else  {
                consOdds=0;
            }
        }
        return false;
    }
};