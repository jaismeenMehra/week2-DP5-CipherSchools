#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root){
  if (!root) {
      return {};
  }
    vector<int> leftView;

    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int sz=nodes.size();
        bool first=true;
        while(sz>0){
            sz--;
            TreeNode<int> *node=nodes.front();
            nodes.pop();
            if (first) {
                leftView.push_back(node->data);
                first=false;
            }
            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
        }
    }
    return leftView;
}