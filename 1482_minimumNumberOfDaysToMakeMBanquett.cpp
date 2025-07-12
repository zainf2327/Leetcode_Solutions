#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    bool isValid(vector<int> &bloomDay, int day, int m, int size)
    {
        int count = 0;
        int curr = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                curr++;
                if (curr == size)
                {
                    count++;
                    curr = 0;
                    if (count == m)
                        return true;
                }
            }
            else
                curr = 0;
        }
        return false;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (m * k > bloomDay.size())
            return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        for (int i = l; i <= r; i++)
        {
            if (isValid(bloomDay, i, m, k))
                return i;
        }
        return -1; // dummy statement
    }
};