class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        
        //level order traversal
        queue<pair<TreeNode *,int>> nodes;
        nodes.push({root,0});
        
        while(!nodes.empty()){
            int sz=nodes.size();
            map<int,vector<int>> temp;//same row -> same col [sort] and then place in original map
            for(int i=0;i<sz;i++){
                auto nodeinode=nodes.front();
                nodes.pop();
                TreeNode *node=nodeinode.first;
                int inode=nodeinode.second;//go left do -1 | go right +1
                temp[inode].push_back(node->val);
                if(node->left){
                    nodes.push({node->left,inode-1});
                }
                if(node->right){
                    nodes.push({node->right,inode+1});
                }
            }
            
            //resolve this level to final output
            map<int,vector<int>>::iterator itr=temp.begin();
            while(itr!=temp.end()){
                vector<int> &x=itr->second;
                sort(x.begin(),x.end());//this row ,column sort
                for(const int &val:x)
                    mp[itr->first].push_back(val);//push col by col to final map matching col
                itr++;
            }
        }
        
        vector<vector<int>> res;

        //resolve final map [sorted from -inf to +inf]
        map<int,vector<int>>::iterator itr=mp.begin();
        while(itr!=mp.end()){
            res.push_back(itr->second);
            itr++;
        }
        return res;
    }
};