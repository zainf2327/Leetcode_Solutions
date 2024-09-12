#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int Max = nums[0], Min = nums[0];
        for (int num : nums) {
            Min = min(Min, num);
            Max = max(Max, num);
        }
        const int SIZE = (Max - Min) + 1;
        vector<int> count(SIZE, 0);
        for (int num : nums) {
            count[num - Min]++;
        }
        vector<vector<int>> freBucket(n + 1);
        for (int i = SIZE - 1; i >= 0; i--) {
            if (count[i] == 0)
                continue;
            freBucket[count[i]].push_back(i + Min);
        }
        vector<int> ans;
        ans.reserve(n);
        for (int i = 1; i <= n; i++) {
            for (int x : freBucket[i]) {
                ans.insert(ans.end(), i, x);
            }
        }
        return ans;
    }
};