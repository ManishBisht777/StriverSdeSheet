void helper(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    helper(root->left, ans);
    helper(root->right, ans);
    ans.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    helper(root, ans);
    return ans;
}