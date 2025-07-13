# include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, h = arr.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            int missing = arr[m] - (m + 1);
            if (missing < k) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return k + h + 1; // k+l
    }
};
