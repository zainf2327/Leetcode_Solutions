#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       int n = nums.size();
        set <int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                return true;
            } else {
                mp.insert(nums[i]);
            }
        }
        return false;
    }
};
