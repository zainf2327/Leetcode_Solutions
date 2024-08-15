#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {

                            // Quick Sort partitions(Two pass)
        
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] != 2) {
                swap(nums[l], nums[r]);
                l++;
            }
        }    // l is size of left partition of having 0 and 1
             // n-l is size of right partition having only 2
            n = l;
            l = 0;
            for (int r = 0; r < n; r++) {
                if (nums[r] != 1) {
                    swap(nums[l], nums[r]);
                    l++;
                }
            }
            // l is size of left partition of having ony zeros
             // n-l is size of right partition having only ones
        
    }

};

