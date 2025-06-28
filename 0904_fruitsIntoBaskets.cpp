# include <unordered_set>
# include <vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        for (int i = 0; i < fruits.size(); i++) {
            unordered_set<int> seen;
            int j;
            for (j = i; j < fruits.size(); j++) {
                seen.insert(fruits[j]);
                if (seen.size() > 2)
                    break;
            }
            maxLen = max(--j - i + 1, maxLen);
        }
        return maxLen;
    }
};