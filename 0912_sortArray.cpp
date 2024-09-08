#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int SIZE = 2 * (5e4) + 1; // 100,001
        int offset = 5e4;               // 50,000
        int count[SIZE] = {0};
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            count[nums[i] + offset]++;
        }
        int j = 0;
        for (int i = 0; i < SIZE; i++) {
            int fre = count[i];
            int num = i - offset;
            while (fre) {
                nums[j] = num;
                j++;
                fre--;
            }
            if (j == n)
                return nums;
        }
        return nums;
    }
};