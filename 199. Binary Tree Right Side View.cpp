class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> res;
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                TreeNode *cur=nodes.front();
                nodes.pop();
                if(sz==0)
                    res.push_back(cur->val);
                
                if(cur->left)
                    nodes.push(cur->left);
                if(cur->right)
                    nodes.push(cur->right);                   
            }
        }
        return res;
    }
};