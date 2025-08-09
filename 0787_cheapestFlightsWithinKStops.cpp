#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> cost(n, 1e9);
        cost[src] = 0;
        queue<pair<int, pair<int, int>>> q; //{steps,{cost,node}};
        q.push({0, {0, src}});

        // we have to visit k+1 levels and from this we have to find the min
        // cost to reach the dest and each node can be visited multiple times
        while (!q.empty()) {
            int curr = q.front().second.second;
            int cs = q.front().first;
            int cc = q.front().second.first;
            q.pop();

            if (cs == k + 1)
                continue;
            for (auto& [nei, dist] : adj[curr]) {
                if (cc + dist < cost[nei]) {
                    cost[nei] = cc + dist;
                    q.push({cs + 1, {cost[nei], nei}});
                }
            }
        }
        if (cost[dst] == 1e9)
            return -1;
        return cost[dst];
    }
};
// TC: O(K*N)  // You are going to visit K levels and at level at worst case u can have all nodes ,it means at each level u may traverse all edges
// SC: O(K*N+N) u queue can have at most states K*n at all levels since each node can be processed(pushed into queue) more than one time.