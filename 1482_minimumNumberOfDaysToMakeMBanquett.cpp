#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    bool isValid(vector<int>& bloomDay, int day, int m, int size) {
        int count = 0;
        int curr = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                curr++;
                if (curr == size) {
                    count++;
                    curr = 0;
                    if (count == m)
                        return true;
                }
            } else
                curr = 0;
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int n, int k) {
        if (n * 1LL * k > bloomDay.size())
            return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(bloomDay, m, n, k)) {
                r = m - 1;
            } else
                l = m + 1;
        }
        return l;
    }
};