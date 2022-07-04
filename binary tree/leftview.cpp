vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return ans;
}