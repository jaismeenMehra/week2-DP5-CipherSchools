class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> res;
        int oddLevel=true;
        while(!nodes.empty()){
            int sz=nodes.size();
            vector<int> temp;
            oddLevel=!oddLevel;
            while(sz>0){
                sz--;
                TreeNode *cur=nodes.front();
                temp.push_back(cur->val);
                nodes.pop();
                if(cur->left)
                    nodes.push(cur->left);
                
                if(cur->right)
                    nodes.push(cur->right);
            }
            if(oddLevel){
                for(int i=0;i<temp.size()/2;i++){
                    int t=temp[i];
                    temp[i]=temp[temp.size()-1-i];
                    temp[temp.size()-1-i]=t;
                }
            }
                
            res.push_back(temp);
        }
        return res;
    }
};