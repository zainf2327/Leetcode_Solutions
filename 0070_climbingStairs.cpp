#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int last2=1;
        int last1=1;  
        for(int i=2;i<=n;i++)   {
            int curr=last1+last2;
            last2=last1;
            last1=curr;
        }
        return last1;

        
        
    }
};