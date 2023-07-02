
#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//! sorted LL to BST
TreeNode * buildTree1(vector<int> &sortedArr,int start,int end){
    if(start>end)   return NULL;
    int mid=start+(end-start)/2;
    TreeNode* newNode =new TreeNode(sortedArr[start]);
    newNode->left=buildTree1(sortedArr,start+1,mid-1);
    newNode->right=buildTree1(sortedArr,mid,end);
    return newNode;    
}

//! Print BST Range


class node
{
	public:
	int data;
	node *left;
	node *right;
};

void Print(node *root, int k1, int k2)
{
	if ( NULL == root )	return;
	
	Print(root->left, k1, k2);
	if ( k1 <= root->data && k2 >= root->data )
		cout<<root->data<<" ";
    Print(root->right, k1, k2);
}

node* newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int main()
{
	node *root = new node();
	int k1 = 10, k2 = 25;

	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	
	Print(root, k1, k2);
	return 0;
}
//! LCA of BST
TreeNode* leastCommonAncestors(TreeNode* root, const int &l,const &r){
    if(root==NULL)  return NULL;
    if(root->val < 1)   return leastCommonAncestors(root->right,l,r);
    else if(root->val > r)  return leastCommonAncestors(root->left,l,r);
    else return root;
}

//!  Unique BST Count -> Generation
// How many BST can be created with n?
class Solution {
public:
    long CalculateCoeff(int n,int k) 
    {
        long res=1;
        if(k>n-k)
            k=n-k;    
        for(int i=0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int numTrees(int n) {
        return CalculateCoeff(2*n,n)/(n+1);
    }
};


//! Unique Binary Search Trees II


class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;
        if(start > end) return {NULL};
        if(start == end) return {new TreeNode(start)};
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> left = solve(start, i-1);
            vector<TreeNode*> right = solve(i+1, end);
            for(auto l: left)
                for(auto r: right)
                    ans.push_back(new TreeNode(i, l, r));
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = solve(1, n);
        return ans;
    }
};