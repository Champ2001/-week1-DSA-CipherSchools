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
 //!Pre-order Recursive
class Solution {
private:
    void solve(vector<int>&ans, TreeNode* root){
        if(root == NULL){
            return ;
        }
        ans.push_back(root->val);
        solve(ans, root->left);
        solve(ans, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans, root);
        return ans;
    }
};

//! Pre-order iterative
vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        if(root == NULL){
            return preorder;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right){
                st.push(root->right);
            }
            if(root->left){
                st.push(root->left);
            }
        }
        return preorder;
    }

//! In - order recursive
class Solution {
    void solve(vector<int>&ans, TreeNode* root){
        if(!root){
            return;
        }
        solve(ans, root->left);
        ans.push_back(root->val);
        solve(ans, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans, root);
        return ans;
    }
};


