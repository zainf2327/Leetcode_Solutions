#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> map; // {email,node}
        int n = accounts.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string& mail = accounts[i][j];
                if (map.count(mail)) {
                    ds.unionBySize(map[mail], i);
                } else
                    map[mail] = i;
            }
        }
        vector<vector<string>> res(n);
        for (auto& it : map) {
            string email = it.first;
            int node = ds.find(it.second);
            res[node].push_back(email);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (res[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), res[i].begin(), res[i].end());
            sort(temp.begin() + 1, temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};