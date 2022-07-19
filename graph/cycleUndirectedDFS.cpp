bool iscycleDFS(vector<int> adj[], vector<int> &vis, int curr, int prev)
{
    vis[curr] = 1;

    for (auto it : adj[curr])
    {
        if (!vis[it])
        {
            if (iscycleDFS(adj, vis, it, curr))
                return true;
        }
        else if (prev != it)
            return true;
    }

    return false;
}