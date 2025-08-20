#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int v) {
        parent.resize(v + 1);
        for (int i = 0; i <= v; i++)
            parent[i] = i;
        size.resize(v + 1, 1);
    }
    int find(int n) { // finds the representative of set(root of tree )
        if (parent[n] == n)
            return n;
        return parent[n] = find(parent[n]); // path optimization
    }
    bool isLeader(int node) { return parent[node] == node; }

    bool unionBySize(int u, int v) {
        int pa = find(u);
        int pb = find(v);
        if (pa == pb)
            return false; // u and v already belongs to same set,cannot make
                          // union operation,indicates cycle in undirected graph
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
            size[pa] = 0; // indicating that it's not a leader of set

        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
            size[pb] = 0; // optional
        }

        return true;
    }
    int componentSize(int node) {
        if (!isLeader(node))
            return 0;
        return size[node];
    }
};
// DisjointSet::find()   O(a(n)) where for very large n ,a is less than 5.
// DisjointSet::union   O(2a(n))
// SC: O(2n)

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int r = 0, c = 0;
        for (auto& stone : stones) {
            r = max(r, stone[0]);
            c = max(c, stone[1]);
        }
        int offset = r+1;
        DisjointSet ds(r + c + 2);
        for (auto& stone : stones) {
            int i = stone[0];
            int j = stone[1] + offset;
            ds.unionBySize(i, j);
        }
        unordered_set<int> leaders;
        int numStones = stones.size();
        for (auto& stone : stones) {
            int i = stone[0];
            leaders.insert(ds.find(i));
        }
        int numComponents = leaders.size();

        return numStones - numComponents;
    }
};