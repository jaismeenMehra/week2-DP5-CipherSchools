#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root) {
  if (!root) {
    return {};
  }
    
    map<int,int> roof; // x coordinate -> vertical elements

    //vertical order traversal -> we push roof only
    queue<pair<BinaryTreeNode<int>*,int>> nodes;
    nodes.push({root,0});
    while (!nodes.empty()) {
        int sz=nodes.size();
        while (sz > 0) {
            sz--;
            auto data=nodes.front();
            nodes.pop();
            BinaryTreeNode<int> *node=data.first;
            int xCord=data.second;
            
            roof[xCord]=node->data;
            if(node->left){
                nodes.push({node->left,xCord-1});
            }
            if (node->right) {
                nodes.push({node->right,xCord+1});
            }
        }
    }
    map<int,int>::iterator itr=roof.begin();
    vector<int> topView;
    while (itr != roof.end()) {
        topView.push_back(itr->second);
        itr++;
    }
    return topView;
}
