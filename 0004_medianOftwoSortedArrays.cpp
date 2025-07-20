# include <vector>
# include <climits>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);      // a is smaller array
         int n1 = a.size(), n2 = b.size();

        int n = n1 + n2;              // total length
        int left = (n1 + n2 + 1) / 2; // size of left half  whereas adding 1 means if total length is odd, it would add to 1 so middle element is added to left half
        
        int low = 0, high = n1;   //we can take a either 0 or all elements form smaller array.
        while (low <= high) {
            int mid1 = (low + high) /2;
            int mid2 = left - mid1;
            // calculate l1, l2, r1 and r2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            // eliminate the halves:
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return -1; // dummy statement
    }
};