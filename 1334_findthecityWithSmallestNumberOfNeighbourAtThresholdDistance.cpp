#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        // Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] < INF && dist[via][j] < INF)
                        dist[i][j] =
                            min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int city = -1;
        int nei = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (dist[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= nei) {
                nei = count;
                city = i;
            }
        }
        return city;
    }
};
