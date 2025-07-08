# include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        for (int num : nums) {
            s = s ^ num;
        }
        return s;
    }
};