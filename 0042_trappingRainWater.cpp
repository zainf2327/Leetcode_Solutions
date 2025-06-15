#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0];
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int r = n - 2; r >= 0; r--) {
            rightMax[r] = max(rightMax[r + 1], height[r]);
        }
        int res = 0;

        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            res += min(leftMax, rightMax[i]) - height[i];
        }
        return res;
    }
};