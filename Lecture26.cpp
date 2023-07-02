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


//! Path form root to leaf 
void helper(TreeNode* root, vector<string>&answer, string curr){
        if(!root){
            return;
        }

        if(root->left||root->right)curr+=(to_string(root->val)+"->");
        else{
            curr += to_string(root->val);
            answer.push_back(curr);
        }
        helper(root->left,answer, curr);
        helper(root->right, answer, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr= "";
        vector<string>answer;
        helper(root, answer, curr);
        return answer;
    }
//! Print ancestors of a node in a binary tree 
bool printAncestors(TreeNode<int> *p, int target,vector<int>&ans)
{
  if (p == NULL)
     return false;
 
  if (p->data == target)
     return true;
  /*
   Print this node if the target is present in either the left or right subtree.
  */
  if ( printAncestors(p->left, target,ans) || printAncestors(p->right, target,ans))
  {
      ans.push_back(p->data);
    return true;
  }
 
  return false;
}

vector<int> ancestorsInBinaryTree(TreeNode<int> *root,int k){
    vector<int>ans;
    
    printAncestors(root, k, ans);
    if(ans.size() <= 0){
        ans.push_back(-1);
    }
    return ans;

}

//!LCA 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }

    }

//! Binary tree to doubly linked list 
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev) {
    if(root == NULL){
        return NULL;
    }
    BinaryTreeNode<int>* leftDLL = BTtoDLL(root->left, prev);

    if(prev){
        root->left = prev;
        prev->right = root;
    }
    else{
        leftDLL = root;
    }
    prev = root;

    BinaryTreeNode<int>* rightDLL = BTtoDLL(root->right, prev);
    if(rightDLL){
        rightDLL->left = root;
        root->right = rightDLL;
    }
    return leftDLL;
}


BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    return BTtoDLL(root, prev);
}

//! Serialize and deserialize

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        queue<TreeNode*>q;
        q.push(root);
        string s="";

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                s.append("#,");
            }
            else{
                s.append(to_string(node->val)+',');
            }
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        queue<TreeNode*>q;
        string str;
        stringstream s(data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else {
                TreeNode* leftNode= new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(node->left);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(node->right);
            }
        }
        return root;
    }
};
