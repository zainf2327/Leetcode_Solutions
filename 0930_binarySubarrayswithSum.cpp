# include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum = sum + nums[j];
                if (sum > goal)
                    break;
                else if (sum == goal)
                    count++;
            }
        }
        return count;
    }
};