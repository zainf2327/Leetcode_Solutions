#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {

                            // Quick Sort Partitions(Three Partitions)(One Pass)
        
       int r = nums.size() - 1;
        int l = 0;
        int m = 0;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[l], nums[m]);
                l++;
                m++;
            } else if (nums[m] == 1) {
                m++;
            } else {
                swap(nums[m], nums[r]);
                r--;
            }
        }
                // l is size of left partition having only zeros.
                // m-l is size of middle partition having only ones.
                // nums.size() - m is size of right partition having only ones.  
    }

};

