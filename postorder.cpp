#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

void postOrder(TreeNode *root, vector<int> &res) {
  if (!root) {
      return;
  }
  postOrder(root->left,res);
  postOrder(root->right,res);
  res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    postOrder(root,res);
    return res;
}
