#include <vector>
#include <climits>
using namespace std;
class Solution {
private:
    int maxPiles(vector<int>& piles) {
        int m = INT_MIN;
        for (int pile : piles) {
            m = max(m, pile);
        }
        return m;
    }
    bool isValid(vector<int>& piles, int eatingSpeed, int hours) {
        int requiredHours = 0;
        for (int pile : piles) {
             requiredHours += ceil((float)pile / eatingSpeed);;
            if (requiredHours > hours)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n > h)
            return -1;
        int r = maxPiles(piles);
        for (int l = 1; l <= r; l++) {
            if (isValid(piles, l, h))
                return l;
        }
        return -1;
    }
};
