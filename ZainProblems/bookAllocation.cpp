# include <vector>
# include <numeric> 
# include <algorithm> 
using namespace std;

class Solution
{
    bool isValid(vector<int> &arr, int numStudents, int pages)
    {
        int stu = 1;
        int p = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if ((p + arr[i]) > pages)
            {
                stu++;
                if (stu > numStudents)
                    return false;
                p = arr[i];
            }
            else
                p += arr[i];
        }
        return true;
    }

public:
    int findPages(vector<int> &arr, int k)
    {
        // code here
        if (k > arr.size())
            return -1;
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (isValid(arr, k, m))
            {
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return l;
    }
};