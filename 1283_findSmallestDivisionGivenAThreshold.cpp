# include <vector> 
# include <climits> 
using namespace std;

class Solution {
private:
    int getMax(vector<int>& nums) {
        int m = INT_MIN;
        for (int num : nums) {
            m = max(m, num);
        }
        return m;
    }
    bool isValid(vector<int>& nums, int divisor, int threshold) {
        int requiredThreshold = 0;
        for (int num : nums) {
            requiredThreshold += ((num + divisor - 1) / divisor);
            if (requiredThreshold > threshold)
                return false;
        }
        return true;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold)
            return -1;
        int l = 1;
        int r = getMax(nums);
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(nums, m, threshold)) {
                r = m - 1;
            }

            else
                l = m + 1;
        }
        return l;
    }
};