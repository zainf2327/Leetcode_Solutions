#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        auto comparator = [&count](int a, int b) {
            if (count[a] != count[b])
                return count[a] < count[b];
            return a > b;
        };
        sort(nums.begin(), nums.end(), comparator);
        return nums;
    }
};