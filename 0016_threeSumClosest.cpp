#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)  {
        int n = nums.size(),sum=0;
        int minDistance=INT_MAX,currentDistance,closestSum;

        for(int i =0;i<n-2;i++) {
             for(int j =i+1;j<n-1;j++)    {
                    for(int k=j+1;k<n;k++)    {
                        sum=nums[i]+nums[j]+nums[k];
                            if(sum==target) return sum;
                            currentDistance=abs(target-sum);
                            if(currentDistance<minDistance) {
                                minDistance = currentDistance;
                                closestSum= sum;
                            }
                    }
            }
        }
        return closestSum;
        
    }
};
int main()  {
             
             
             
    return 0;
}