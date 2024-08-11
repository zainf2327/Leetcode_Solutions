#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int minDistance = INT_MAX;
        int closestTozero =INT_MIN;
        int n = nums.size();
        for (int i=0 ; i<n; i++) {
            int currentDistance=abs(nums[i]-0);
            if ( currentDistance < minDistance) {
                minDistance=currentDistance;
                closestTozero = nums[i];
            } else if (currentDistance == minDistance) {
                 closestTozero = max(nums[i],closestTozero);
            }
        }
        return closestTozero;
    }
};