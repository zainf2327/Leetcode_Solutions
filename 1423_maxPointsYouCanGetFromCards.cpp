# include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int curSum = 0, maxSum = 0, n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            curSum += cardPoints[i]; // intialize our current window
        }
        maxSum = curSum;
        for (int j = k - 1; j >= 0; j--) {
            curSum -= cardPoints[j];
            curSum += cardPoints[n + j - k];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};