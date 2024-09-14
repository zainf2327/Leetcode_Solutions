#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int altitude = min(height[j], height[i]);
                int area = width * altitude;
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};