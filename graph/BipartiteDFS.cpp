#include <bits/stdc++.h>
bool dfs(int node, vector<int> adj[], vector<int> &color)
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!dfs(it, adj, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}