#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int l = 1, r = n - 2; l < n; l++, r--) {
            leftMax[l] = max(leftMax[l - 1], height[l]);
            rightMax[r] = max(rightMax[r + 1], height[r]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};