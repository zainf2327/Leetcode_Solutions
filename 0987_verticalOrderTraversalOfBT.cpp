#include <bits/stdc++.h>

using namespace std;
class TreeNode {
public: 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        // col -> row -> nodes
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q; // {node, {col,row}}
        q.push({root, {0,0}});

        while (!q.empty()) {
            auto [curr, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;

            nodes[col][row].insert(curr->val);

            if (curr->left)  q.push({curr->left, {col-1, row+1}});
            if (curr->right) q.push({curr->right, {col+1, row+1}});
        }

        vector<vector<int>> res;
        for (auto& [col, rows] : nodes) {
            vector<int> level;
            for (auto& [row, vals] : rows) {
                level.insert(level.end(), vals.begin(), vals.end());
            }
            res.push_back(level);
        }
        return res;
    }
};
