#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>zigzag(Node* root){
    vector<vector<int>>result;
    if(root == NULL){
        return result;
    }
    queue<Node*>q;
    q.push(root);
    bool leftTORight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int>row;

        for(int i = 0;i<size;i++){
            Node *node = q.front();
            q.pop();

            int index = leftTORight ? i : (size - i - 1);
            row[index] = node->val;

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        leftTORight = !leftTORight;
        result.push_back(row);
    }
    return result;
}

    