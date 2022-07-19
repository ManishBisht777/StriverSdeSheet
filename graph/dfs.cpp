void dfs(vector<int> &ans, vector<int> &vis, vector<int> adj[], int curr)
{

    ans.push_back(curr);
    vis[curr] = 1;

    for (auto it : adj[curr])
        if (!vis[it])
            dfs(ans, vis, adj, it);
}

vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(ans, vis, adj, i);
    }

    return ans;
}