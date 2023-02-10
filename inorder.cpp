#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

// void inorder(TreeNode *root, vector<int> &res) {
//   if (!root) {
//       return;
//   }
//   inorder(root->left,res);
//   res.push_back(root->data);
//   inorder(root->right,res);
// }

void inorder(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    stack<TreeNode*> stck;

    while (root || !stck.empty()) {
        while (root!=NULL) {
            stck.push(root);
            root=root->left;
        }
        TreeNode *tp=stck.top();
        stck.pop();
        res.push_back(tp->data);
        
        if(tp->right){
            root=tp->right;
        }
    }
}

vector<int> getInOrderTraversal(TreeNode *root){
    vector<int> res;
    inorder(root,res);
    return res;
}