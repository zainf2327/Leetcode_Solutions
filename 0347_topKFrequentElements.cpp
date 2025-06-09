#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        auto compare = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second > b.second;
        };

        sort(freqVec.begin(), freqVec.end(), compare);
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
