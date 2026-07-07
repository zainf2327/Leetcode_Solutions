#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 };
 

class Solution{

bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

void addLeft(TreeNode* curr,vector<int>& res) {
    if(!curr || isLeaf(curr)) return ;
    res.push_back(curr->data);
    if(curr->left) addLeft(curr->left,res);
    else addLeft(curr->right,res);
}

void addLeaves(TreeNode* root,vector<int>& res) {
    if(!root) return ;

    if(isLeaf(root)) {
        res.push_back(root->data);
        return ;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}

void addRight(TreeNode* curr,vector<int>& res) {
    if(!curr || isLeaf(curr)) return ;
    
    if(curr->right) addRight(curr->right,res);
    else addRight(curr->left,res);
    
    res.push_back(curr->data);

}

public:
    vector <int> boundary(TreeNode* root){
        if(!root) return {};
    	vector<int> res;
        if(!isLeaf(root) ) {
            res.push_back(root->data);
        }
        addLeft(root->left,res);
        addLeaves(root,res);
        addRight(root->right,res);
        return res;
    }
};