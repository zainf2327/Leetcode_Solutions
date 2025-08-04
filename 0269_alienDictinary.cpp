#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool buildList(string& str1, string& str2,  unordered_map<char, unordered_set<char>>& adj, unordered_map<char, int>& indegree) {

        int n1 = str1.size(), n2 = str2.size();
        int l = 0;
        while (l < n1 && l < n2) {
            if (str1[l] != str2[l]) {
                if (adj[str1[l]].insert(str2[l]).second) {
                    // Only increment indegree if it's the first time
                    indegree[str2[l]]++;
                }
                return true;
            }
            l++;
        }
        // If str1 is longer and str2 is prefix → invalid case
        return n1 <= n2;
    }

public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all unique characters
        for (const string& word : words) {
            for (char c : word) {
                adj[c];       // ensures character is in adj map
                indegree[c];  // ensures character is in indegree map
            }
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            if (!buildList(words[i], words[i + 1], adj, indegree)) {
                return "";  // Invalid order due to prefix issue
            }
        }

        // Topological sort (Kahn's algorithm)
        queue<char> q;
        for (auto& [c, indeg] : indegree) {
            if (indeg == 0) q.push(c);
        }

        string order;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            order.push_back(curr);

            for (char nei : adj[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return (order.size() == adj.size()) ? order : "";
    }
};

//TC: O(N*M+ N*M + V+E)
// SC:O(@6+26+26)