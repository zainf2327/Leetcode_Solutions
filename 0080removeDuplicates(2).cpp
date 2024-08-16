#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++) {
            int count = 1;
            while ((r + 1) < n && nums[r + 1] == nums[r]) {
                count++;
                r++;
            }
            count = min(count, 2);
            while (count) {
                nums[l] = nums[r];
                l++;
                count--;
            }
        }
        return l;
    }
};