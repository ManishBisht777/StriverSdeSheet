bool iscycle(vector<int> adj[], vector<int> &vis, int curr)
{
    queue<pair<int, int>> q;
    q.push({curr, -1});
    vis[curr] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if (prev != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycle(vector<int> adj[], int n)
{

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && iscycle(adj, vis, i))
            return true;
    }

    return false;
}