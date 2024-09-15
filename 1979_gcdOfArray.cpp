#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        for (int i = min; i > 1; i--) {
            if (min % i == 0 && max % i == 0) {
                return i;
            }
        }
        return 1;
    }
};