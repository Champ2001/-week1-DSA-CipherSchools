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


//!Root to leaf max sum
bool isLeaf(TreeNode* root){
        if(root && !root->left && !root->right){
            return true;
        }
        return false;
    }
    void maxPathSum(TreeNode* root, int sum , int &maxsum){
        if(!root){
            return;
        }
        sum += root->val;
        if(isLeaf(root)){
            maxsum = max(maxsum , sum);
            return;
        }
        else{
            maxPathSum(root->left, sum , maxsum);
            maxPathSum(root->right, sum , maxsum);
        }
    }

    int sumNumbers(TreeNode* root) {
        int maxsum = 0;
        maxPathSum(root, 0, maxsum);
        return maxsum;
    }

//! Binary Tree Maximum Path Sum


int maximumPathDown(TreeNode* root, int maxi){
        if(root == NULL){
            return 0;
        }
        int left = max(0,maximumPathDown(root->left, maxi));
        int right = max(0, maximumPathDown(root->right, maxi));
        maxi = max(maxi, (root->val+left+right));
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maximumPathDown(root, maxi);
        return maxi;
    }

//! Construct binary tree from preorder and inorder
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode *root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRoot = mp[root->val];
        int numsleft = inRoot - inStart;
        
        root->left =buildTree(preorder,preStart+1,preStart+numsleft,inorder,inStart,inRoot-1,mp);
        root->right =buildTree(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,mp);
        return root;
    }