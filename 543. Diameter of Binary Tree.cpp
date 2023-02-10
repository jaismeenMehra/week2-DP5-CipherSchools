class Solution {
private:
    int diameterOfBinaryTree(TreeNode* root,int &dia) {
         //max length to left + max length to right
         //preorder
        if(!root)
            return 0;
        int a=diameterOfBinaryTree(root->left,dia);
        int b=diameterOfBinaryTree(root->right,dia);
        dia=max(dia,a+b);
        return 1+max(a,b);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        diameterOfBinaryTree(root,dia);
        return dia;
    }
};

//store max dia so far and return max length branch