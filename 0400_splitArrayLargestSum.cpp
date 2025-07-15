# include <vector>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
    bool isValid(vector<int>& arr, int numSubarrays, int maxSum) {
        int subarray = 1;
        int currSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((currSum + arr[i]) > maxSum) {
                subarray++;
                if (subarray > numSubarrays)
                    return false;
                currSum = arr[i];
            } else
                currSum += arr[i];
        }
        return true;
    }

public:
    int splitArray(vector<int>& arr, int k) {
        if (k > arr.size())
            return -1;
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(arr, k, m)) {
                r = m - 1;
            } else
                l = m + 1;
        }
        return l;
    }
};