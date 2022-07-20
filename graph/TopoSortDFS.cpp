void dfs(vector<int> adj[], vector<int> &vis, stack<int> &st, int node)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(adj, vis, st, it);
    }

    st.push(node);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here

    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(adj, vis, st, i);
    }

    vector<int> ans;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }
    return ans;
}