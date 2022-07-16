string serialize(TreeNode *root)
{

    string s = "";
    if (!root)
        return s;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (!curr)
            s.append("#,");
        else
            s.append(to_string(curr->val) + ',');

        if (curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{

    if (data.size() == 0)
        return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(str));
    q.push(root);

    while (!q.empty())
    {
        TreeNode *root = q.front();
        q.pop();

        getline(s, str, ',');

        if (str == "#")
        {
            root->left = NULL;
        }
        else
        {
            TreeNode *leftnode = new TreeNode(stoi(str));
            root->left = leftnode;
            q.push(leftnode);
        }

        getline(s, str, ',');

        if (str == "#")
        {
            root->right = NULL;
        }
        else
        {
            TreeNode *rightnode = new TreeNode(stoi(str));
            root->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
}
;