bool helper(TreeNode<int> *root, vector<int> &ans, int x)
{
    if (!root)
        return false;

    if (root->data == x)
    {
        ans.push_back(root->data);
        return true;
    }

    ans.push_back(root->data);
    if (helper(root->left, ans, x))
        return true;
    if (helper(root->right, ans, x))
        return true;
    ans.pop_back();

    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    helper(root, ans, x);
    return ans;
}