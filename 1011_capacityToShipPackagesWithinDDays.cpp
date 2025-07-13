# include <vector>
# include<numeric>
# include<algorithm>
using namespace std;
class Solution {
private:
bool isValid(vector<int>& weights, int days,int capacity)  {
        int n = weights.size();
        int d = 1;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr + weights[i] <= capacity) {
                curr += weights[i];
            } else {
                d++;
                if (d > days)
                    return false;
                curr = weights[i];
            }
        }
        return true;
}
public:

    int shipWithinDays(vector<int>& weights, int days) {
         int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(weights, days, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};