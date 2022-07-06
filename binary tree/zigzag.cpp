vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if (!root)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    bool dir = false;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            temp.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (dir)
        {
            reverse(temp.begin(), temp.end());
        }

        ans.insert(ans.end(), temp.begin(), temp.end());
        dir = !dir;
    }

    return ans;
}