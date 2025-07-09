#include <vector>
#include <climits> 
#include <cmath> 
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
             requiredHours += ceil((float)pile / eatingSpeed);
            // requiredHours += (pile + eatingSpeed - 1) / eatingSpeed;
            // ceil((double)a/b) ===== (a+b-1)/b   whera a and b are both positive integers only.

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
        int l = 1;
        int r = maxPiles(piles);
        while (l <= r) {
            int m = (l + r) / 2;
            if (isValid(piles, m, h)) {
                r = m - 1;
            }

            else
                l = m + 1;
        }
        return l;
    }
};

