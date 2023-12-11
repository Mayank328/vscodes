void dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[i] = 1;
    for (auto adjnode : adj[i])
    {
        if (!vis[adjnode])
        {
            dfs(adjnode, adj, vis, st);
        }
    }
    st.push(i);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i += 1)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}