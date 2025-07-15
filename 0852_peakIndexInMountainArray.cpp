# include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int r = arr.size() - 2;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1]) {
                return m;
            }
            if (arr[m] > arr[m + 1]) {
                r = m - 1;
            } else
                l = m + 1;
        }
        return -1;
    }
};