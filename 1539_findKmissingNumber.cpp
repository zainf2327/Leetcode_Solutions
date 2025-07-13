# include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0;
        for (i = 0; i < n; i++) {
            if ((arr[i] - i - 1) >= k) {
                break;
            }
        }

        if (i == 0)
            return k;
        i--;

        int pre = arr[i];
        int more = k - (arr[i] - (i + 1));
        return pre + more; // k+i+1;
    }
};
