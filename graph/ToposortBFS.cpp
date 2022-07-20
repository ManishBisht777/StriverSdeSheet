vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    queue<int> q;
    vector<int> indeg(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }

    return ans;
}