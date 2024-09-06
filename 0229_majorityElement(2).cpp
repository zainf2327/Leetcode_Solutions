#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (map.size() < 2) {
                map[nums[i]]++;
            } else if (map.count(nums[i])) {
                map[nums[i]]++;
            } else {
                unordered_map<int, int> temp;
                for (auto& pair : map) {
                    pair.second--;
                    if (pair.second > 0) {
                        temp.insert({pair.first, pair.second});
                    }
                }
                map = temp;
            }
        }
        vector<int> ans;
        int threshold = n / 3;
        for (auto& pair : map) {
            pair.second = 0;
        }
        for (int i = 0; i < n; i++) {
            if (map.count(nums[i])) {
                map[nums[i]]++;
            }
        }
        for (auto& pair : map) {
            if (pair.second > threshold) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};