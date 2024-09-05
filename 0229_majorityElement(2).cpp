#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                count2++;
            } else if (candidate1 == nums[i]) {
                count1++;
            } else if (candidate2 == nums[i]) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int threshold = n / 3;
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            }
        }
        if (count1 > threshold) {
            ans.push_back(candidate1);
        }
        if (count2 > threshold) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};