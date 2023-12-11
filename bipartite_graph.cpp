bool bfs(int i, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adjnode : adj[node])
        {
            if (color[adjnode] == -1)
            {
                color[adjnode] = !color[node];
                q.push(adjnode);
            }
            else if (color[adjnode] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i += 1)
    {
        if (color[i] == -1)
        {
            if (bfs(i, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}