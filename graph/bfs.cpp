vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<int> vis(V, 0);

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return ans;
}