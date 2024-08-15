#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {

                            // Quick Sort partitions(Two pass)
        
        int r = nums.size()-1;
        int l = 0;
       while(l<=r)  {
          if(nums[l]==2)    {
            swap(nums[l],nums[r]);
            r--;
          }
          else{
            l++;
          }
       }
              // l is size of left partition of having 0 and 1
             //  n-l is size of right partition having only 2
            r=l-1;
            l = 0;
            while(l<=r)  {
            if(nums[l]==1)    {
                swap(nums[l],nums[r]);
                r--;
          }
          else{
            l++;
          }
       }
            // l is size of left partition of having ony zeros
             // l(old)-l(new) is size of right partition having only ones
        
    }

};

