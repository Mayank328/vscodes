bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &pathvis, vector<int> &check)
{
    vis[i] = 1;
    pathvis[i] = 1;
    check[i] = 1;
    for (auto adjnode : adj[i])
    {
        if (!vis[adjnode])
        {
            if (dfs(adjnode, adj, vis, pathvis, check))
            {
                check[i] = 0;
                return true;
            }
        }
        else if (pathvis[adjnode])
        {
            check[i] = 0;
            return true;
        }
    }
    check[i] = 1;
    pathvis[i] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    vector<int> check(V, 0);
    vector<int> safe_state;
    for (int i = 0; i < V; i += 1)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, pathvis, check);
        }
    }
    for (int i = 0; i < check.size(); i += 1)
    {
        if (check[i] == 1)
        {
            safe_state.push_back(i);
        }
    }
    return safe_state;
}