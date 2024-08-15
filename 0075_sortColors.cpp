#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Counting Sort(Two pass)
        int zeros = 0;
        int ones = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
        }
        for (int i = 0; i < n; i++) {
            if (zeros) {
                nums[i] = 0;
                zeros--;
            } else if (ones) {
                nums[i] = 1;
                ones--;
            } else {
                nums[i] = 2;
            }
        }
    }

};

