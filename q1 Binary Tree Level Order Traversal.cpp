class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> lvl;
        queue<TreeNode *> res;
        res.push(root);
        while(!res.empty()){
            vector<int> temp;
            int sz=res.size();
            while(sz>0){
                sz--;
                TreeNode *cur=res.front();
                res.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    res.push(cur->left);
                if(cur->right)
                    res.push(cur->right);
            }
            lvl.push_back(temp);
        }
        return lvl;
    }
};