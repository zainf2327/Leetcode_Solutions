#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sorted Array
        if (nums[0] > 0)
            return {}; // Base case
        vector<vector<int>> triples;
        int sum = 0, start, end;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            start = i + 1, end = n - 1;
            while (start < end) {
                sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    triples.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1])  // Skipping duplicates possible
                        start++;
                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                } else if (sum > 0){
                    end--;
                    while (start < end && nums[end] == nums[end + 1])  // Next triplet would be same, so don't need to check them.
                        end--;
                }
                else{
                    start++;
                    while (start < end && nums[start] == nums[start - 1])   // Next triplet would be same, so don't need to check them.
                    start++;
                }
            }
        }

        return triples;
    }
};
