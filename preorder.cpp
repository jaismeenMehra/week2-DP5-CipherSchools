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
// void preOrder(TreeNode *root, vector<int> &res) {
//   if (!root) {
//       return;
//   }
//   res.push_back(root->val);
//   preOrder(root->left,res);
//   preOrder(root->right,res);
// }

void preOrder(TreeNode *root, vector<int> &res) {
  stack<TreeNode*> stck;
  stck.push(root);

  while(!stck.empty()){
      TreeNode *tp=stck.top();
      stck.pop();
      res.push_back(tp->val);
      if(tp->right){
          stck.push(tp->right);
      }
      if(tp->left){
          stck.push(tp->left);
      }
  }
}
vector<int> preorderTraversal(TreeNode* root)
{
    	vector<int> res;
        preOrder(root,res);
        return res;
}