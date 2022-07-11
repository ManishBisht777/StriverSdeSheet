TreeNode *helper(vector<int> &preorder, int &i, int max)
{
    if (i == preorder.size() || preorder[i] > max)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);

    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, max);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{

    int i = 0;
    return helper(preorder, i, INT_MAX);
}