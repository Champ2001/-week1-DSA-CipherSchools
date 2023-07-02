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

//! In - order iterative
vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* node = root;

        vector<int>ans;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
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