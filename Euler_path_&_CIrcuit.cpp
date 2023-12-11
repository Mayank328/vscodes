class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &vis, int i)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(adj, vis, it);
            }
        }
    }
    bool isConnected(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        int i;
        for (i = 0; i < V; i += 1)
        {
            if (adj[i].size() > 0)
                break;
        }
        dfs(adj, vis, i);
        for (i = 0; i < V; i += 1)
        {
            if (!vis[i] and adj[i].size() > 0)
                return false;
        }
        return true;
    }
    int isEularCircuit(int V, vector<int> adj[])
    {
        if (!isConnected(V, adj))
            return 0;
        int odd = 0;
        for (int i = 0; i < V; i += 1)
        {
            if (adj[i].size() & 1)
            {
                odd += 1;
            }
        }
        if (odd > 2)
            return 0;
        return odd ? 1 : 2;
    }
};