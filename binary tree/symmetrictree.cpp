bool helper(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        else if((left &&!right)|| (right && !left)) return false;
        else if(left->val!=right->val) return false;
        
        return helper(left->left, right->right) && helper(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return false;
        
        return helper(root->left, root->right);
    }