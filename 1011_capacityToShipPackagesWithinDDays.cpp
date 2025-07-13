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
        for (int i = l; i <= r; i++) {
            if (isValid(weights, days, i)) {
                return i;
            }
        }
        return -1;
    }
};