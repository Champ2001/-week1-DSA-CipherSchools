#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i = 0;i< size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
//! Diameter of a binary tree
int height(int &diameter, TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(diameter, root->left);
        int right = height(diameter, root->right);
        diameter = max(left+right, diameter);
        return 1+max(left, right);
}
int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(diameter, root);
        return diameter;
}

//! Vertical Order Traversal
vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Storing node's value and levels in a queue
    queue<pair<TreeNode*, pair<int, int>>> todo;
    // Storing nodes with levels in a multimap
    map<int, map<int, multiset<int>>> nodes;
    todo.push(make_pair(root, make_pair(0, 0)));
    
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        
        if (node->left) {
            todo.push(make_pair(node->left, make_pair(x - 1, y + 1)));
        }
        if (node->right) {
            todo.push(make_pair(node->right, make_pair(x + 1, y + 1)));
        }
    }
    
    vector<vector<int>> ans;
    for (auto& p : nodes) {
        vector<int> cols;
        for (auto& q : p.second) {
            cols.insert(cols.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(cols);
    }
    
    return ans;
}
