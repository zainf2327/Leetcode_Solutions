# include <unordered_map>
# include <vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0, l = 0;
        unordered_map<int, int> seen;
        for (int r = 0; r < fruits.size(); r++) {
            seen[fruits[r]]++;
            if (seen.size() > 2) {
                seen[fruits[l]]--;
                if (seen[fruits[l]] == 0)
                    seen.erase(fruits[l]);
                l++;
            }
            if (seen.size() <= 2) {
                maxLen = max(r - l + 1, maxLen);
            }
        }
        return maxLen;
    }
};