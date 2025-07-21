#include <vector>
#include <queue>
using namespace std;

class Solution  {
public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size(); // size of array.
        int howManyPlaced[n - 1] = {0};
        priority_queue<pair<double, int>> pq;               // max heap by default
                                                        // pair here is { sectionLength,sectionIndex}

        for (int i = 0; i < n - 1; i++)     {
            pq.push({arr[i + 1] - arr[i], i});              // heapfying the heap with all the sections
        }

        for (int j = 1; j <= k; j++)    {
            auto tp = pq.top();
            pq.pop();

            int index = tp.second;
            howManyPlaced[index]++;

            int diff = arr[index + 1] - arr[index];
            double sectionLength = (double)diff / (howManyPlaced[index] + 1);
            pq.push({sectionLength, index});
        }

        return pq.top().first;
    }
};