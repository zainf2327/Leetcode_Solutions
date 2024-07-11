#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        int sum;
        while (start < end) {
            sum = numbers[start] + numbers[end];
            if (sum == target)
                return {start + 1, end + 1};
            else if (sum > target)
                end--;
            else
                start++;
        }

        return {};  //Return empty array if no pair is found that add to target
    }
};