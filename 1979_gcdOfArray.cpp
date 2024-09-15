#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNumber = nums[0], minNumber = nums[0];
        for (int num : nums) {
            maxNumber = max(maxNumber, num);
            minNumber = min(minNumber, num);
        }
        while (minNumber != 0) {
            int temp = minNumber;
            minNumber = maxNumber % minNumber;
            maxNumber = temp;
        }
        return maxNumber;
    }
};