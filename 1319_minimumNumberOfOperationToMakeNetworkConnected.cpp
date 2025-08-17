#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> size;

public:
    vector<int> parent;
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

    bool Union(int u, int v) {
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
};

class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for (auto& connection : connections) {
            if (!ds.Union(connection[0], connection[1]))
                extraEdges++;
        }
        int numComponents = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                numComponents++;
        }
        if (extraEdges < (numComponents - 1))
            return -1;
        return numComponents - 1;
    }
};