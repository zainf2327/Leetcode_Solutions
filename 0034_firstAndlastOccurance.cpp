# include <vector>
using namespace std;

class Solution {
private:
    int search(vector<int>& nums, int target, bool forFirst) {
        int l = 0, r = nums.size() - 1;
        int index = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                index = m;
                if (forFirst)
                    r = m - 1;
                else
                    l = m + 1;
            } else if (target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = search(nums, target, true);
        if (first == -1)
            return {-1, -1};
        int last = search(nums, target, false);
        return {first, last};
    }
};