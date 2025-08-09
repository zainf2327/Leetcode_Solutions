#include<vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int curr = pq.top().second;
            int ct = pq.top().first;
            pq.pop();
            if (ct > time[curr])
                continue;
            for (auto& [nei, nt] : adj[curr]) {
                if (ct + nt < time[nei]) {
                    time[nei] = ct + nt;
                    pq.push({time[nei], nei});
                }
            }
        }
        int timeRequired = 0;
        for (int j = 1; j <= n; j++) {
            if (time[j] == 1e9)
                return -1;
            timeRequired = max(timeRequired, time[j]);
        }
        return timeRequired;
    }
};


// SC: O(V+E)(adjacency)+O(V)(distance)+O(E)(priority queue)=O(E+V)
// TC: O(VlogV+ ElogV) (Dikstra Algorithm)