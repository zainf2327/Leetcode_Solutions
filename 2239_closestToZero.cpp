#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int closestTozero =nums[0];
        int n = nums.size();
        for (int i=1 ; i<n; i++) {
            
            if ( abs(nums[i]) < abs(closestTozero)) {
                closestTozero = nums[i];
            } else if ( abs(nums[i])== abs(closestTozero)) {
                 closestTozero = max(nums[i],closestTozero);
            }
        }
        return closestTozero;
    }
};