void helper(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    helper(root->left, ans);
    ans.push_back(root->data);
    helper(root->right, ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    helper(root, ans);
    return ans;
}