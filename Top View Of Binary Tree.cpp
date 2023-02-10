#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
  if (!root) {
    return {};
  }
    map<int,int> roof; // x coordinate -> vertical elements

    //vertical order traversal -> we push roof only
    queue<pair<TreeNode<int>*,int>> nodes;
    nodes.push({root,0});
    while (!nodes.empty()) {
        int sz=nodes.size();
        while (sz > 0) {
            sz--;
            auto data=nodes.front();
            nodes.pop();
            TreeNode<int> *node=data.first;
            int xCord=data.second;
            auto itr=roof.find(xCord);
            if (itr == roof.end()) {
                roof[xCord]=node->val;
            }
            if(node->left){
                nodes.push({node->left,xCord-1});
            }
            if (node->right) {
                nodes.push({node->right,xCord+1});
            }
        }
    }
    map<int,int>::const_iterator itr=roof.cbegin();
    vector<int> topView;
    while (itr != roof.cend()) {
        topView.push_back(itr->second);
        itr++;
    }
    return topView;
}